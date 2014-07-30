//
//  main.cpp
//  BSTree
//
//  Created by Alps on 14-7-29.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType char

using namespace std;

struct Tree;
typedef Tree* TreeNode;

struct Node;
typedef Node* PtrToNode;
typedef PtrToNode Stack;

struct Tree{
    ElementType element;
    TreeNode  left;
    TreeNode  right;
};

struct Node{
    TreeNode rootNode;
    Stack Next;
};
/****************** Stack operate ****************/

Stack createStack(void){
    Stack S = (Stack)malloc(sizeof(Stack));
    S->Next = NULL;
    return S;
}

int isEmptyStack(Stack S){
    return S->Next == NULL;
}

void Push(TreeNode T, Stack S){
    Stack SNode = (Stack)malloc(sizeof(Node));
    SNode->rootNode = NULL;
    SNode->Next = NULL;
    SNode->rootNode = T;
    SNode->Next = S->Next;
    S->Next = SNode;
}

TreeNode Top(Stack S){
    if (!isEmptyStack(S)) {
        return S->Next->rootNode;
    }else{
//        printf("stack is empty, can't get top element!\n");
        return NULL;
    }
}

void Pop(Stack S){
    if (!isEmptyStack(S)) {
        Stack tmp = S->Next;
        S->Next = tmp->Next;
        free(tmp);
        tmp = NULL;
    }else{
        printf("stack is empty, can't pop the stack!\n");
        exit(1);
    }
}

Stack switchStack(Stack S){
    Stack tmp = (Stack)malloc(sizeof(Node));
    Stack switchTmp = S->Next;
    while (switchTmp != NULL) {
        Push(switchTmp->rootNode, tmp);
        switchTmp = switchTmp->Next;
    }
    return tmp;
}

int findStack(TreeNode T, Stack S){
    Stack tmp = S->Next;
    while (tmp != NULL) {
        if (tmp->rootNode == T) {
            return 1;
        }
        tmp = tmp->Next;
    }
    return 0;
}

void PrintStack(Stack S){
    if (S == NULL) {
        printf("please create stack first!\n");
        exit(1);
    }
    Stack tmp = S->Next;
    while (tmp != NULL) {
        ElementType X = tmp->rootNode->element;
        printf("%c ",X);
        tmp = tmp->Next;
    }
    printf("\n");
    
}
/****************** Tree operate ****************/

TreeNode createNode(ElementType X){
    TreeNode expressionTree = (TreeNode)malloc(sizeof(Tree));
    expressionTree->element = X;
    expressionTree->left = NULL;
    expressionTree->right = NULL;
    return expressionTree;
}

TreeNode createTree(ElementType A[], int length, Stack S){
    int i = 0;
    TreeNode tmpNode;
    for (i = 0; i < length; i++) {
        tmpNode = createNode(A[i]);
        if (tmpNode->element == '+' || tmpNode->element == '-' || tmpNode->element == '*' || tmpNode->element == '/') {
            tmpNode->right = Top(S);
            Pop(S);
            tmpNode->left = Top(S);
            Pop(S);
            Push(tmpNode, S);
        }else{
            Push(tmpNode, S);
        }
    }
    return S->Next->rootNode;
}

int PushTreeNode(TreeNode T, Stack S){
    if (T == NULL) {
        return 0;
    }else{
        Push(T, S);
        PushTreeNode(T->left, S);
        PushTreeNode(T->right, S);
    }
    return 0;
}


void PreorderPrint(TreeNode T){
    Stack S = createStack();
    if (T == NULL) {
        printf("empty tree\n");
        exit(1);
    }
    PushTreeNode(T, S);
    S = switchStack(S);
    PrintStack(S);
}

void inOrder(TreeNode T){
    Stack S = createStack();
    TreeNode tmpTree;
    if (T == NULL) {
        printf("empty tree\n");
        exit(1);
    }
    while (T) {
        Push(T, S);
        T = T->left;
        if (T == NULL) {
            while (1) {
                tmpTree = Top(S);
                if (tmpTree == NULL) {
                    break;
                }
                printf("%c ",tmpTree->element);
                if (tmpTree->right != NULL) {
                    T = tmpTree->right;
                    Pop(S);
                    break;
                }else{
                    Pop(S);
                }
            }
        }
    }
    printf("\n");
}

void afterPreorder(TreeNode T){
    Stack S = createStack();
    TreeNode tmpTree;
    Stack saveS = createStack();
    if (T == NULL) {
        printf("empty tree\n");
        exit(1);
    }
    while (T) {
        Push(T, S);
        T = T->left;
        if (T == NULL) {
            while (1) {
                tmpTree = Top(S);
                if (tmpTree == NULL) {
                    break;
                }
                if (tmpTree->right != NULL) {
                    if (findStack(tmpTree, saveS)) {
                        printf("%c ",tmpTree->element);
                        Pop(S);
                        continue;
                    }
                    Push(tmpTree, saveS);
                    T = tmpTree->right;
                    break;
                }else{
                    printf("%c ",tmpTree->element);
                    Pop(S);
                }
            }
        }
    }
    printf("\n");
}

/****************** Main        ****************/



int main(int argc, const char * argv[])
{
    char A[] = {'a','b','+','c','d','e','+','*','*'};
    Stack S = createStack();
    int length = sizeof(A)/sizeof(char);
    TreeNode T = createTree(A, length, S);
//    printf("%lu\n",sizeof(Node));
    printf("create Tree success!\n");
    PreorderPrint(T);
    inOrder(T);
    afterPreorder(T);
    return 0;
}

