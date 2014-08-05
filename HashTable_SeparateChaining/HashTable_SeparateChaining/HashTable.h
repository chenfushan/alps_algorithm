//
//  HashTable.h
//  HashTable_SeparateChaining
//
//  Created by Alps on 14-8-5.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#ifndef HashTable_SeparateChaining_HashTable_h
#define HashTable_SeparateChaining_HashTable_h
#define ElementType int

struct ListNode;
typedef struct ListNode *Position;
struct HashTb;
typedef HashTb *HashTable;

HashTable InitializeTable(int Tablesize);
void Destory(HashTable H);
Position Find(ElementType key, HashTable H);
void Insert(ElementType key, HashTable H);

#endif

struct ListNode{
    ElementType element;
    Position Next;
};

typedef Position List;

struct HashTb{
    int Tablesize;
    List * TheList;
};
