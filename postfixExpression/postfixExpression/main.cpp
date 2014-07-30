//
//  main.cpp
//  postfixExpression
//
//  Created by Alps on 14-7-28.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType double

using namespace std;

struct Node;
typedef Node * PtrToNode;
typedef PtrToNode Stack;

struct Node{
    ElementType X;
    PtrToNode Next;
};

Stack createStack(){
    Stack S;
    S = (Stack)malloc(sizeof(Node));
    S->Next = NULL;
    return S;
}

int isEmpty(Stack S){
    return S->Next == NULL;
}

void Push(Stack S, ElementType element){
    Stack tmp;
    tmp = (Stack)malloc(sizeof(Node));
    tmp->X = element;
    tmp->Next = S->Next;
    S->Next = tmp;
}

ElementType Top(Stack S){
    if (!isEmpty(S)) {
        return S->Next->X;
    }else{
        printf("Stack is empty, can't return top element!\n");
        return 0;
    }
    return 0;
}

void Pop(Stack S){
    if (!isEmpty(S)) {
        Stack tmp = S->Next;
        S->Next = tmp->Next;
        free(tmp);
    }else{
        printf("Stack is empty, can't pop!\n");
    }
}

int makeEmpty(Stack S){
    if (S == NULL) {
        printf("please create stack first!\n");
        return 0;
    }
    while (!isEmpty(S)) {
        Pop(S);
    }
    return 0;
}

void stackAdd(Stack S){
    double tmp1, tmp2;
    tmp1 = Top(S);
    Pop(S);
    tmp2 = Top(S);
    Pop(S);
    tmp1 += tmp2;
    Push(S, tmp1);
}

void stackSubstraction(Stack S){
    double tmp1,tmp2;
    tmp1 = Top(S);
    Pop(S);
    tmp2 = Top(S);
    Pop(S);
    tmp1 -= tmp2;
    Push(S, tmp1);
}

void stackMultiplication(Stack S){
    double tmp1,tmp2;
    tmp1 = Top(S);
    Pop(S);
    tmp2 = Top(S);
    Pop(S);
    tmp1 *= tmp2;
    Push(S, tmp1);
}

void stackDivision(Stack S){
    double tmp1,tmp2;
    tmp1 = Top(S);
    Pop(S);
    tmp2 = Top(S);
    Pop(S);
    tmp1 = tmp1/tmp2;
    Push(S, tmp1);
}

void postfixExpression(Stack S, char *A, int length){
    int i = 0;
    double tmp1;
    for (i = 0; i < length; i++) {
        switch (A[i]) {
            case '+':
                stackAdd(S);
                break;
            case '-':
                stackSubstraction(S);
                break;
            case '*':
                stackMultiplication(S);
                break;
            case '/':
                stackDivision(S);
                break;
                
            default:
                tmp1 = (int)A[i]-48;
                Push(S, tmp1);
                break;
        }
    }
}


int main(int argc, const char * argv[])
{
    char A[]={'6','5','2','3','+','8','*','+','3','+','*'};
    int lengthA = sizeof(A)/sizeof(char);
    Stack S = createStack();
    double result;
    postfixExpression(S, A, lengthA);
    result = Top(S);
    printf("%.2f\n",result);
    return 0;
}

