//
//  main.cpp
//  HashTable_SeparateChaining
//
//  Created by Alps on 14-8-5.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "HashTable.h"
#define MinTableSize 1

using namespace std;

bool Prime(int size){
    for (int i = 2; i < sqrt(size); i++) {
        if (size%i == 0) {
            return false;
        }
    }
    return true;
}

int NextPrime(int Tablesize){
    if (Tablesize <= 2) {
        return 2;
    }else{
        while (!Prime(Tablesize)) {
            Tablesize++;
        }
        return Tablesize;
    }
    return Tablesize;
}

HashTable InitializeTable(int Tablesize){
    HashTable H;
    int i;
    
    if (Tablesize < MinTableSize) {
//        Error("table size is too small!");
        exit(0);
    }
    H = (HashTable)malloc(sizeof(struct HashTb));
    if (H == NULL) {
        //Error("out of space");
        exit(0);
    }
    H->Tablesize = NextPrime(Tablesize);
    H->TheList = (List*)malloc(sizeof(List) * H->Tablesize);
    for (i = 0; i < H->Tablesize; i++) {
        H->TheList[i] = (List)malloc(sizeof(struct ListNode));
        H->TheList[i]->Next = NULL;
    }
    
    return H;
}

int Hash(int key, int Tablesize){
    return key%Tablesize;
}

Position Find(ElementType key, HashTable H){
    int i = Hash(key, H->Tablesize);
    List L = H->TheList[i]->Next;
    while (L != NULL && L->element != key) {
        L = L->Next;
    }
    return L;
}

void Insert(ElementType key, HashTable H){
    if (Find(key, H) == NULL) {
        int i = Hash(key, H->Tablesize);
        List L = (List)malloc(sizeof(struct ListNode));
        L->element = key;
        Position P = H->TheList[i];
        L->Next = P->Next;
        P->Next = L;
    }
}


int main(int argc, const char * argv[])
{
    HashTable H = InitializeTable(10);
    printf("%d\n",H->Tablesize);
    Insert(5, H);
    Insert(3, H);
    Position P = Find(5, H);
    printf("%d\n",P->element);
    return 0;
}

