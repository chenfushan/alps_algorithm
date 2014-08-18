//
//  main.cpp
//  binaryHeap
//
//  Created by Alps on 14-8-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "binaryHeap.h"
//#define ElementType int
using namespace std;

PriorityQuenue Initialize(int MaxNum){
    PriorityQuenue P = (PriorityQuenue)malloc(sizeof(struct HeapStruct));
    if (P == NULL) {
        //error("can't malloc memory");
        exit(1);
    }
    P->elements = (ElementType *)malloc(MaxNum * sizeof(ElementType));
    if (P->elements == NULL) {
        //error("can't malloc memory");
        exit(1);
    }
    P->Capacity = MaxNum;
    P->Size = 0;
    P->elements[0] = 0;
    return P;
}

void Destory(PriorityQuenue P){
    if (P != NULL && P->elements != NULL) {
        free(P->elements);
        free(P);
    }
}

void MakeEmpty(PriorityQuenue P){
    if (P != NULL && P->elements != NULL) {
        free(P->elements);
        P->elements = (ElementType *)malloc(P->Capacity * sizeof(ElementType));
        P->Size = 0;
    }
}

int IsEmpty(PriorityQuenue P){
    if (P != NULL) {
        return P->Size == 0;
    }else{
        return 1;
    }
}

int IsFull(PriorityQuenue P){
    if (P != NULL) {
        return P->Size == P->Capacity-1;
    }else{
        //error("P is not exist");
        return 1;
    }
}

void Insert(PriorityQuenue P, ElementType X){
    int i = 0;
    if (!IsFull(P)) {
        P->elements[P->Size+1] = X;
        P->Size++;
        for (i = P->Size; P->elements[i/2] > X; i /=2) {
            P->elements[i/2] = P->elements[i] + P->elements[i/2];
            P->elements[i] = P->elements[i/2] - P->elements[i];
            P->elements[i/2] = P->elements[i/2] = P->elements[i];
        }
        P->elements[i] = X;
    }else{
        //error("the PriorityQuenue is already full");
        return;
    }
}

ElementType FindMin(PriorityQuenue P){
    if (!IsEmpty(P)) {
        return P->elements[1];
    }else{
        return NULL;
    }
}

ElementType DeleteMin(PriorityQuenue P){
    ElementType MinElement, LastElement;
    int temp;
    int i = 1;
    if (!IsEmpty(P)) {
        MinElement = P->elements[1];
        LastElement = P->elements[P->Size];
        for (i = 1; i*2 < P->Size; i = temp) {
            temp = i*2;
            if (temp != P->Size) {
                if (P->elements[temp] < P->elements[temp+1]) {
                    P->elements[i] = P->elements[temp];
                }else{
                    P->elements[i] = P->elements[temp+1];
                    temp++;
                }
            }
            if (LastElement < P->elements[i]) {
                P->elements[i] = LastElement;
//                P->Size--;
                break;
            }
        }
        P->elements[i] = LastElement;
        P->Size--;
        return MinElement;
    }else{
        return NULL;
    }
}



int main(int argc, const char * argv[])
{
    PriorityQuenue P = Initialize(20);
    Insert(P, 13);
    Insert(P, 21);
    Insert(P, 16);
    Insert(P, 24);
    Insert(P, 31);
    Insert(P, 19);
    Insert(P, 68);
    Insert(P, 65);
    Insert(P, 26);
    Insert(P, 32);
    Insert(P, 14);
    for (int i = 1; i <= P->Size; i++) {
       printf("%d ",P->elements[i]);
    }
    printf("\n");
    DeleteMin(P);
    for (int i = 1; i <= P->Size; i++) {
        printf("%d ",P->elements[i]);
    }
    printf("\n");
    return 0;
}

