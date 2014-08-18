//
//  binaryHeap.h
//  binaryHeap
//
//  Created by Alps on 14-8-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#ifndef binaryHeap_binaryHeap_h
#define binaryHeap_binaryHeap_h
#define ElementType int

struct HeapStruct;
typedef HeapStruct *PriorityQuenue;

PriorityQuenue Initialize(int MaxNum);
void Destory(PriorityQuenue P);
void MakeEmpty(PriorityQuenue P);
void Insert(PriorityQuenue P);
ElementType DeleteMin(PriorityQuenue P);
ElementType FindMin(PriorityQuenue P);
int IsEmpty(PriorityQuenue P);
int IsFull(PriorityQuenue P);

struct HeapStruct{
    int Capacity;
    int Size;
    ElementType *elements;
};


#endif
