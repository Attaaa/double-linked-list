#include "doublelist.h"

void inputTilZero(List &L) {
    infotype input;
    do {
        cout << "Input Real Number: ";
        cin >> input;
        if (input != 0) {
            address P = alokasi(input);
            insertFirst(L,P);
        }
    } while (input != 0);
}

int lengthList(List L) {
    int length = 0;
    address P = first(L);
    while (P != NULL) {
        length++;
        P = next(P);
    }
    return length;
}

int sumListInfo(List L) {
    int sum = 0;
    address P = first(L);
    while (P != NULL) {
        sum = sum + info(P);
        P = next(P);
    }
    return sum;
}

void oddEven(List L, List &oddList, List &evenList) {
    address P = first(L);
    address temp;
    while (P != NULL) {
        temp = alokasi(info(P));
        if (info(P) % 2 == 0)
            insertFirst(evenList, temp);
        else
            insertFirst(oddList, temp);
        P = next(P);
    }
}

infotype maxInfo(List L) {
    address P = first(L);
    infotype max = 0;
    while (P != NULL) {
        if (info(P) > max)
            max = info(P);
        P = next(P);
    }
    return max;
}

void insertionSort(List &L) {
    if (first(L) != NULL) {
        address P = first(L);
        while (next(P) != NULL) {
            address currentAdr = next(P);
            while ( (prev(currentAdr) != NULL) && ( info(currentAdr) < info(prev(currentAdr)) ) ) {
                infotype temp = info(currentAdr);
                info(currentAdr) = info(prev(currentAdr));
                info(prev(currentAdr)) = temp;
                currentAdr = prev(currentAdr);
            }
            P = next(P);
        }
    }
}

void selectionSort(List &L) {
    if (first(L) != NULL) {
        address P = first(L);
        while (next(P) != NULL) {
            address nextAdr = next(P);
            address minAdr = P;
            while (nextAdr != NULL) {
                if (info(nextAdr) < info(minAdr)) {
                    minAdr = nextAdr;
                }
                nextAdr = next(nextAdr);
            }
            infotype temp = info(P);
            info(P) = info(minAdr);
            info(minAdr) = temp;
            P = next(P);
        }
    }
}

int main(){
    List L;
    createList(L);

    inputTilZero(L);
    printInfo(L);

    cout << "List Length: " << lengthList(L) << endl;
    cout << "Sum List Info: " << sumListInfo(L) << endl;

    List oddList, evenList;
    createList(oddList);
    createList(evenList);

    oddEven( L , oddList , evenList );
    printInfo(oddList);
    printInfo(evenList);

    cout << "Maximum Number in List L: " << maxInfo(L) << endl;

    //insertionSort(L);
    selectionSort(L);
    printInfo(L);

    return 0;
}