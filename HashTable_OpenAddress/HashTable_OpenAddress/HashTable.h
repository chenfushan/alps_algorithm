//
//  HashTable.h
//  HashTable_OpenAddress
//
//  Created by Alps on 14-8-6.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#ifndef HashTable_OpenAddress_HashTable_h
#define HashTable_OpenAddress_HashTable_h

#define ElementType int

struct HashEntry;
typedef HashEntry* entry;
typedef unsigned int Index;
typedef Index Position;
struct HashTb;
typedef HashTb* HashTable;
HashTable InitializeHashTable(int TableSize);
Position Find(ElementType X, HashTable H);
void Insert(ElementType X, HashTable H);
HashTable ReHash(HashTable H);

enum KindOfEntry{empty ,full};

struct HashEntry{
    ElementType element;
    KindOfEntry info;
};

typedef entry Cell;

struct HashTb{
    int TableSize;
    Cell TheCells;
};



#endif
