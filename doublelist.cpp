#include "doublelist.h"

void createList(List &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    if (first(L) == NULL) {
        insertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (next(Prec) == NULL) {
        insertLast(L,P);
    } else {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

address findElm(List &L, infotype x) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == x) {
            return P;
        }
        P = next(P);
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    if (first(L) != NULL) {
        P = first(L);
        if (next(P) == NULL) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            next(P) = NULL;
            prev(first(L)) = NULL;
        }
    }
}

void deleteLast(List &L, address &P) {
    if (last(L) != NULL) {
        P = last(L);
        if (next(P) == NULL) {
            deleteFirst(L,P);
        } else {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = next(Prec);
    if (P != NULL) {
        if (P == last(L)) {
            deleteLast(L,P);
        } else {
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void printInfo(List L) {
    address P = first(L);
    while (P != NULL) {
        cout << info(P);
        if (P != last(L)) {
            cout << " - ";
        }
        P = next(P);
    }
    cout << endl;
}