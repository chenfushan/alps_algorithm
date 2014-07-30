//
//  main.cpp
//  LinkList
//
//  Created by Alps on 14-7-25.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
//Position Header(List L);
//Position First(List L);
//Position Advance(List L);
//int Retrieve(Position P);
void Print(List L);

struct Node{
    int Element;
    Position Next;
};

void Print(List L){
    Position P;
    P = L->Next;
    while (P != NULL) {
        printf("%d ",P->Element);
        P = P->Next;
    }
    printf("\n");
}

int IsEmpty(List L){
    return L->Next == NULL;
}

int IsLast(Position P, List L){
    return P->Next == NULL;
}


Position Find(int X, List L){
    Position P;
    P = L->Next;
    while (P->Element != X && P != NULL) {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(int X, List L){
    Position P;
    P = L->Next;
    while (P->Next->Element != X && P->Next != NULL) {
        P = P->Next;
    }
    return P;
}

void Delete(int X, List L){
    Position P;
    P = FindPrevious(X, L);
    Position tmp;
    if (!IsLast(P, L)) {
        tmp = P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}

//void Delete(int X, List *L){
//    Position *P;
//    *P = Find(X, *L);
//    Position *tmp;
//    if (!IsLast(*P, *L)) {
//        tmp = P;
//        *P = (*P)->Next;
//        free(*tmp);
//    }
//}

void Insert(int X, List L, Position P){
    Position tmp = (Position)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("out of memory in fun Insert\n");
    }
    tmp->Element = X;
    tmp->Next = P->Next;
    P->Next = tmp;
}

void DeleteList(List L){
    Position P, tmp;
    P = L->Next;
    tmp = P->Next;
    while (P != NULL) {
        free(P);
        if (tmp == NULL) {
            break;
        }
        P = tmp;
        tmp = P->Next;
    }
    L->Next = NULL;
}



int main(int argc, const char * argv[])
{
    List L = (List)malloc(sizeof(struct Node));
    Insert(1, L, L);
    Insert(3, L, L->Next);
    Insert(5, L, L->Next->Next);
    Print(L);
    Position P = Find(3, L);
    printf("%d\n",P->Element);
    P = FindPrevious(3, L);
    printf("%d\n",P->Element);
    Delete(3, L);
    Print(L);
//    DeleteList(L);
    Print(L);
    
    return 0;
}

