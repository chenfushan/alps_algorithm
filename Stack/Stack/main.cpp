//
//  main.cpp
//  Stack
//
//  Created by Alps on 14-7-27.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node;
typedef Node * PtrToNode;
typedef PtrToNode Stack;

struct Node{
    int X;
    PtrToNode Next;
};

int isEmpty(Stack S){
    return S->Next == NULL;
}

Stack createStack(void){
    Stack S;
    S = (Stack)malloc(sizeof(Stack));
    S->Next = NULL;
    return S;
}

void Push(Stack S, int X){
    Stack element;
    element = (Stack)malloc(sizeof(Stack));
    element->X = X;
    element->Next = S->Next;
    S->Next = element;
}

void Pop(Stack S){
    if (!isEmpty(S)) {
        Stack tmp = S->Next;
        S->Next = tmp->Next;
        free(tmp);
    }else{
        printf("Empty stack can't pop cell\n");
    }
}

int Top(Stack S){
    int X;
    if (!isEmpty(S)) {
        return X = S->Next->X;
    }else{
        printf("empty stack, no top cell\n");
    }
    return 0;
}

void makeEmpty(Stack S){
    if (S == NULL) {
        printf("create stack first\n");
    }
    while (!isEmpty(S)) {
        Pop(S);
    }
}

int main(int argc, const char * argv[])
{
    Stack S = createStack();
    Push(S, 2);
    Push(S, 4);
    Push(S, 6);
    Push(S, 8);
    printf("%d\n",Top(S));
    Pop(S);
    printf("%d\n",Top(S));
    makeEmpty(S);
    printf("%d\n",Top(S));
    return 0;
}

