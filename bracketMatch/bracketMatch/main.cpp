//
//  main.cpp
//  bracketMatch
//
//  Created by Alps on 14-7-28.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType char

using namespace std;

struct Node;
typedef Node * PtrToNode;
typedef PtrToNode Stack;

struct Node{
    ElementType X;
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

void Push(Stack S, ElementType X){
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

ElementType Top(Stack S){
    ElementType X;
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
    int i = 0;
    char tmp;
    int flag = 0;
    char A[] = {'(','b','c',')','[','{','a','(',')','c','}',']'};
    for (i = 0; i < sizeof(A)/sizeof(char); i++) {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{') {
            Push(S, A[i]);
            continue;
        }else{
            if (A[i] == ')' || A[i] == ']' || A[i] == '}') {
                tmp = Top(S);
                switch (A[i]) {
                    case ')':
                        if (tmp == '(') {
                            flag = 1;
                        }
                        break;
                    case ']':
                        if (tmp == '[') {
                            flag = 1;
                        }
                        break;
                    case '}':
                        if (tmp == '{') {
                            flag = 1;
                        }
                        break;
                        
                    default:
                        break;
                }
                if (flag != 1) {
                    printf("the bracket doesn't match! %c-%d\n",A[i],i);
                    return 1;
                }else{
                    Pop(S);
                    flag = 0;
                }
            }else{
                continue;
            }
        }
    }
    if (!isEmpty(S)) {
        printf("there are already some barackets not matched!\n");
        return 1;
    }else{
        printf("the bracket is matched\n");
    }
    return 0;
}



