#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include<iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

typedef int infotype;

typedef struct elmlist *address;

struct elmlist {
    address next;
    address prev;
    infotype info;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
address findElm(List &L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void printInfo(List L);

#endif // DOUBLELIST_H_INCLUDED