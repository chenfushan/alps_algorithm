//
//  main.cpp
//  AVL
//
//  Created by Alps on 14-8-7.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "AVL.h"

int Height(AVL A){
    if (A == NULL) {
        return -1;
    }else{
        return A->height;
    }
}
int MAX(int a, int b){
    return a>b?a:b;
}

AVL SingleRotateWithRight(AVL A){
    AVL tmp = A->right;
    A->right = tmp->left;
    tmp->left = A;
    A->height = MAX(Height(A->left), Height(A->right))+1;
    tmp->height = MAX(Height(tmp->left), Height(tmp->right))+1;
    return tmp;
}

AVL DoubleRotateWithRight(AVL A){
    AVL tmp = A->right;
    AVL tmp1 = tmp->left;
    tmp->left = tmp1->right;
    A->right = tmp1->left;
    tmp1->right = tmp;
    tmp1->left = A;
    tmp->height = MAX(Height(tmp->left), Height(tmp->right))+1;
    A->height = MAX(Height(A->left), Height(A->right))+1;
    tmp1->height = MAX(Height(tmp1->left), Height(tmp1->right))+1;
    return tmp1;
}

AVL SingleRotateWithLeft(AVL A){
    AVL tmp = A->left;
    A->left = tmp->right;
    tmp->right = A;
    A->height = MAX(Height(A->left), Height(A->right))+1;
    tmp->height = MAX(Height(tmp->left), Height(tmp->right))+1;
    return tmp;
}

AVL DoubleRotateWithLeft(AVL A){
    AVL tmp = A->left;
    AVL tmp1 = tmp->right;
    tmp->right = tmp1->left;
    A->left = tmp1->right;
    tmp1->left = tmp;
    tmp1->right = A;
    tmp->height = MAX(Height(tmp->left), Height(tmp->right))+1;
    A->height = MAX(Height(A->left), Height(A->right))+1;
    tmp1->height = MAX(Height(tmp1->left), Height(tmp1->right))+1;
    return tmp1;
}



AVL Insert(ElementType key, AVL A){
    if (A == NULL) {
        A = (AVL)malloc(sizeof(struct TreeNode));
        A->element = key;
        A->height = 0;
        A->right = NULL;
        A->left = NULL;
//        return A;
    }else{
        if (key > A->element) {
            A->right = Insert(key, A->right);
            if (Height(A->right) - Height(A->left) == 2) {
                if (key > A->right->element) {
                    A = SingleRotateWithRight(A);
                }else{
                    A = DoubleRotateWithRight(A);
                }
            }
            
        }else
            if (key < A->element) {
               A->left = Insert(key, A->left);
                if (Height(A->left) - Height(A->right) == 2) {
                    if (key < A->left->element) {
                        A = SingleRotateWithLeft(A);
                    }else{
                        A = DoubleRotateWithLeft(A);
                    }
                }
            }
    }
    
    A->height = MAX(Height(A->left), Height(A->right))+1;
    return A;
}

Position FindMax(AVL A){
    AVL tmp = A;
    if (A == NULL) {
        return NULL;
    }else{
        while (tmp->right != NULL) {
            tmp = tmp->right;
        }
    }
    return tmp;
}

Position FindMin(AVL A){
    AVL tmp = A;
    if (A == NULL) {
        return NULL;
    }else{
        while (tmp->left != NULL) {
            tmp = tmp->left;
        }
    }
    return tmp;
}

Position Find(ElementType key,AVL A){
    AVL tmp = A;
    if (A == NULL) {
        return NULL;
    }else{
        while (tmp != NULL && tmp->element != key) {
            if (key > tmp->element) {
                tmp = tmp->right;
            }else{
                tmp = tmp->left;
            }
        }
    }
    return tmp;
}

AVL Delete(ElementType key, AVL A){
    
    if (A == NULL || Find(key, A) == NULL) {
        return NULL;
    }else{
        
        if (key == A->element) {
            AVL tmp;
            if (A->left && A->right) {
                tmp = FindMin(A->left);
                A->element = tmp->element;
                A->left = Delete(A->element, A->left);
            }else{
                tmp = A;
                if (A->left) {
                    A = A->left;
                }else{
                    if (A->right) {
                        A = A->right;
                    }else{
                        A = NULL;
                    }
                }
                free(tmp);
                tmp = NULL;
                return A;
            }
        }else{
            if (key > A->element) {
                A->right = Delete(key, A->right);
                if (Height(A->left) - Height(A->right) == 2) {
                    if (A->left->right != NULL && (Height(A->left->right) > Height(A->left->left))) {
                        A = DoubleRotateWithLeft(A);
                    }else{
                        A = SingleRotateWithLeft(A);
                    }
                }
//                A->height = MAX(Height(A->left), Height(A->right));
            }else{
                if (key < A->element) {
                    A->left = Delete(key, A->left);
                    if (Height(A->right) - Height(A->left) == 2) {
                        if (A->right->left != NULL && (Height(A->right->left) > Height(A->right->right))) {
                            A = DoubleRotateWithRight(A);
                        }else{
                            A = SingleRotateWithRight(A);
                        }
                    }
//                    A->height = MAX(Height(A->left), Height(A->right));
                }
            }
        }
    }
    A->height = MAX(Height(A->left), Height(A->right))+1;
    return A;
}


int main(int argc, const char * argv[])
{
    AVL A = NULL;
    A = Insert(3, A);
    printf("%d %d\n",A->element,A->height);
    A = Insert(2, A);
    printf("%d %d\n",A->left->element,A->height);
    A = Insert(1, A);
    printf("%d %d\n",A->left->element,A->left->height);
    A = Insert(4, A);
    A = Insert(5, A);
    printf("%d %d\n",A->right->element,A->right->height);
    A = Insert(6, A);
    printf("%d %d\n",A->element,A->height);
    A = Insert(7, A);
    A = Insert(16, A);
    A = Insert(15, A);
    printf("%d %d\n",A->right->element,A->right->height);
    A = Insert(14, A);
    printf("%d %d\n",A->right->element,A->right->height);
    A = Delete(16, A);
    printf("%d %d\n",A->right->element,A->right->height);
    A = Delete(6, A);
    A = Delete(5, A);
    printf("%d %d\n",A->right->element,A->right->height);
    return 0;
}

