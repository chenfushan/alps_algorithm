//
//  main.cpp
//  BSTree
//
//  Created by Alps on 14-7-31.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int

using namespace std;

struct Node;
typedef Node* PtrToNode;
typedef PtrToNode TreeNode;

TreeNode makeEmpty(TreeNode T);
int isEmpty(TreeNode T);
TreeNode findTree(ElementType X,TreeNode T);
TreeNode findMin(TreeNode T);
TreeNode findMax(TreeNode T);
TreeNode insertTree(ElementType X, TreeNode T);
TreeNode deleteTree(ElementType X, TreeNode T);

struct Node{
    ElementType element;
    TreeNode left;
    TreeNode right;
};

TreeNode makeEmpty(TreeNode T){
    if (T != NULL) {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

int isEmpty(TreeNode T){
    return T == NULL;
}

TreeNode findTree(ElementType X,TreeNode T){
    if (T == NULL) {
        return NULL;
    }
    if (X < T->element) {
        return findTree(X, T->left);
    }else if(X > T->element){
        return findTree(X, T->right);
    }else{
        return T;
    }
}

TreeNode findMin(TreeNode T){
    if (T == NULL) {
        return NULL;
    }
    if (T->left == NULL) {
        return T;
    }else{
        return findMin(T->left);
    }
//    return NULL;
}

TreeNode findMax(TreeNode T){
    if (T == NULL) {
        return NULL;
    }
    if (T->right  == NULL) {
        return T;
    }else{
        return findMax(T->right);
    }
//    return NULL;
}

TreeNode insertTree(ElementType X, TreeNode T){
    if (T == NULL) {
        T = (TreeNode)malloc(sizeof(Node));
        T->element = X;
        T->left = NULL;
        T->right = NULL;
    }else if(X > T->element){
        T->right = insertTree(X, T->right);
    }else if(X < T->element){
        T->left = insertTree(X, T->left);
    }
    return T;
}

TreeNode deleteTree(ElementType X, TreeNode T){
    TreeNode XNode = findTree(X, T);
    if (XNode == NULL || T == NULL) {
        printf("can't find the node is : %d",X);
        exit(1);
    }
    if (X > T->element) {
        T->right = deleteTree(X, T->right);
    }else if(X < T->element){
        T->left = deleteTree(X, T->left);
    }else{
        TreeNode tmp;
        if (T->left && T->right) {
            tmp = findMin(T->right);
            T->element = tmp->element;
            T->right = deleteTree( T->element, T->right);
        }else{
            tmp = T;
            if (T->left == NULL) {
                T = T->right;
            }else
            if (T->right == NULL) {
                T = T->left;
            }
            free(tmp);
            tmp = NULL;
        }
    }
    return T;
}

void PreOrderTree(TreeNode T){
    if (T != NULL) {
        printf("%d ",T->element);
        PreOrderTree(T->left);
        PreOrderTree(T->right);
    }
}

int main(int argc, const char * argv[])
{

    TreeNode T = (TreeNode)malloc(sizeof(Node));
    T = makeEmpty(T);
    T = insertTree(6, T);
    T = insertTree(2, T);
    T =insertTree(8, T);
    T =insertTree(1, T);
    T = insertTree(5, T);
    T =insertTree(3, T);
    T = insertTree(4, T);
//    printf("%d\n",T->element);
    PreOrderTree(T);
    printf("\n");
    TreeNode tmp;
    tmp = findTree(2, T);
    printf("%d\n",tmp->element);
    T = deleteTree(2, T);
    PreOrderTree(T);
    printf("\n");
    tmp = findMax(T);
    printf("%d\n",tmp->element);
    tmp = findMin(T);
    printf("%d\n",tmp->element);
//    std::cout << "Hello, World!\n";
    return 0;
}

