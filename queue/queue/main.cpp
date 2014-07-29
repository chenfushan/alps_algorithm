//
//  main.cpp
//  queue
//
//  Created by Alps on 14-7-28.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int

using namespace std;

struct Node;
typedef Node* PtrToNode;
typedef PtrToNode Queue;

struct Node{
    ElementType X;
    PtrToNode Pre;
    PtrToNode Next;
};

Queue createQueue(void){
    Queue Q;
    Queue Q2;
    Q2 = (Queue)malloc(sizeof(Queue));
    Q = (Queue)malloc(sizeof(Queue));
    Q->X = 0;
    Q->Next = Q2;
    Q->Pre = Q2;
    Q2->Next = Q;
    Q2->Pre = Q;
    return Q;
}

int isEmpty(Queue Q){
    return Q->Next->Next == Q;
}

void intoQueue(Queue Q, ElementType element){
    Queue tmp;
    Queue tmp1;
    tmp1 = (Queue)malloc(sizeof(Queue));
//    Queue switchTmp;
    tmp = (Queue)malloc(sizeof(Queue));
    tmp->X = element;
    tmp->Next = Q->Next;
    Q->Next->Pre = tmp;
    Q->Next = tmp;
    tmp->Pre = Q;
}

void outQueue(Queue Q){
    Queue tmp;
    tmp = Q->Pre->Pre;
    Q->Pre->Pre = tmp->Pre;
    tmp->Pre->Next = Q->Pre;
    free(tmp);
}

ElementType headQueue(Queue Q){
    if (Q == NULL) {
        printf("please create queue first!\n");
        return 0;
    }
    if (!isEmpty(Q)) {
        return Q->Pre->Pre->X;
    }else{
        printf("The queue is empty!\n");
        return 0;
    }
}

int makeEmpty(Queue Q){
    if (Q == NULL) {
        printf("please create queue first!\n");
        return -1;
    }
    while (!isEmpty(Q)) {
        outQueue(Q);
    }
    return 0;
}

void Print(Queue Q){
    if (!isEmpty(Q)) {
        Queue tmp = Q->Pre->Pre;
        while (tmp != Q) {
            printf("%d ",tmp->X);
            tmp = tmp->Pre;
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[])
{
    Queue Q = createQueue();
    if (isEmpty(Q)) {
        printf("The queue is empty !\n");
    }else{
        printf("The queue is not empty!\n");
    }
    intoQueue(Q, 2);
    intoQueue(Q, 4);
    intoQueue(Q, 6);
    Print(Q);
    outQueue(Q);
    Print(Q);
    makeEmpty(Q);
    Print(Q);
//    printf("%d\n",headQueue(Q));
    return 0;
}

