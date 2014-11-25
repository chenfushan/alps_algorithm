//
//  main.cpp
//  ThreadBinaryTree
//
//  Created by Alps on 14/11/21.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct TreeNode* node;

struct TreeNode{
    node lchild;
    int ltag;
    int rtag;
    node rchild;
    int data;
};
node Pre = NULL;

void InOrderTree(node n){
    if (n == NULL) {
    }else{
        //        Pre = n;
        if (n->lchild != NULL) {
            n->ltag = 0;
            InOrderTree(n->lchild);
        }else{
            n->ltag = 1;
            n->lchild = Pre;
        }
        if (Pre!=NULL && Pre->rchild == NULL) {
            Pre->rtag = 1;
            Pre->rchild = n;
        }
        Pre = n;
        if (n->rchild != NULL) {
            n->rtag = 0;
            InOrderTree(n->rchild);
        }else{
            n->rtag = 1;
        }
    }
}


int main(int argc, const char * argv[]) {
    node head = (node)malloc(sizeof(struct TreeNode));
    head->data = 1;
    node node1 = (node)malloc(sizeof(struct TreeNode));
    node node2 = (node)malloc(sizeof(struct TreeNode));
    node node3 = (node)malloc(sizeof(struct TreeNode));
    node node4 = (node)malloc(sizeof(struct TreeNode));
    node1->data = 2;
    node2->data = 3;
    node3->data = 4;
    node4->data = 5;
    head->lchild = node1;
    head->rchild = node2;
    node1->lchild = node3;
    node1->rchild = node4;
    node2->lchild = NULL;
    node2->rchild = NULL;
    node3->lchild = NULL;
    node3->rchild = NULL;
    node4->lchild = NULL;
    node4->rchild = NULL;
    InOrderTree(head);
    return 0;
}
