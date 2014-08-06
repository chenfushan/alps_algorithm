//
//  main.cpp
//  HashTable_OpenAddress
//
//  Created by Alps on 14-8-6.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "HashTable.h"
#include <math.h>

#define MinTableSize 1

int Hash(ElementType key, int TableSize){
    return key%TableSize;
}

bool Prime(int num){
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int NextPrime(int TableSize){
    if (TableSize <= 2) {
        return 2;
    }else{
        while (!Prime(TableSize)) {
            TableSize++;
        }
    }
    return TableSize;
}

int PrePrime(int TableSize){
    if (TableSize <= 2) {
        return 2;
    }else{
        TableSize--;
        while (!Prime(TableSize) && TableSize > 2) {
            TableSize--;
        }
    }
    return TableSize;
}

HashTable InitializeHashTable(int TableSize){
    if (TableSize < MinTableSize) {
        //error("it's too small");
        exit(0);
    }
    HashTable H = (HashTable)malloc(sizeof(HashTb));
    H->TableSize = NextPrime(TableSize);
    H->TheCells = (Cell)malloc(sizeof(struct HashEntry) * H->TableSize);
    for (int i = 0; i < H->TableSize; i++) {
        H->TheCells[i].info = empty;
    }
    return H;
}

Position LineFind(ElementType key, HashTable H){
    int i = Hash(key, H->TableSize);
    while (H->TheCells[i].info != empty && H->TheCells[i].element != key) {
        i += 1;
        if (i >= H->TableSize) {
            i = i % H->TableSize;
        }
    }
    return i;
}

Position SquareFind(ElementType key, HashTable H){
    int i = Hash(key, H->TableSize);
    int num = 0;
    while (H->TheCells[i].info != empty && H->TheCells[i].element != key) {
        i -= num*num;
        ++num;
        i += num*num;
        if (i >= H->TableSize) {
            i = i % H->TableSize;
        }
    }
    return i;
}

Position DoubleHashFind(ElementType key, HashTable H){
    int i = Hash(key, H->TableSize);
    int num = PrePrime(H->TableSize);
    num =num - key%num;
    while (H->TheCells[i].info != empty && H->TheCells[i].element != key) {
        i += num;
        if (i >= H->TableSize) {
            i = i % H->TableSize;
        }
    }
    return i;
}

Position Find(ElementType key, HashTable H){
//    return LineFind(key, H);
//    return SquareFind(key, H);
    return DoubleHashFind(key, H);
}

void LineInsert(ElementType key, HashTable H){
    Position P = LineFind(key, H);
    if (H->TheCells[P].info != full) {
        H->TheCells[P].element = key;
        H->TheCells[P].info = full;
    }
}

void SquareInsert(ElementType key, HashTable H){
    Position P = SquareFind(key, H);
    if (H->TheCells[P].info != full) {
        H->TheCells[P].element = key;
        H->TheCells[P].info = full;
    }
}

void DoubleHashInsert(ElementType key, HashTable H){
    Position P = DoubleHashFind(key, H);
    if (H->TheCells[P].info != full) {
        H->TheCells[P].element = key;
        H->TheCells[P].info = full;
    }
}

void Insert(ElementType key, HashTable H){
//    LineInsert(key, H);
//    SquareInsert(key, H);
    DoubleHashInsert(key, H);
}

int main(int argc, const char * argv[])
{
    HashTable H = InitializeHashTable(10);
    Insert(5, H);
//    printf("%d\n",H->TableSize);
    Position P = Find(5, H);
    printf("%d\n",H->TheCells[P].element);
    printf("%d\n",P);
    /////////////////////////////////////
    Insert(16, H);
//    printf("%d\n",H->TableSize);
    P = Find(16, H);
    printf("%d\n",H->TheCells[P].element);
    printf("%d\n",P);
    /////////////////////////////////////
    Insert(27, H);
//    printf("%d\n",H->TableSize);
    P = Find(27, H);
    printf("%d\n",H->TheCells[P].element);
    printf("%d\n",P);
    return 0;
}

