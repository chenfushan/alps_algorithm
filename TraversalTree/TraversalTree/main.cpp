//
//  main.cpp
//  TraversalTree
//
//  Created by Alps on 14/11/23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
struct TreeNode;
typedef TreeNode* Node;
typedef int EleType;

struct TreeNode{
    Node lchild;
    Node rchild;
    EleType data;
};

void PreOrderTree(Node node){
    if (node != NULL) {
        printf("%d\n",node->data);
        PreOrderTree(node->lchild);
        PreOrderTree(node->rchild);
    }
}

void InOrderTree(Node node){
    if (node != NULL) {
        InOrderTree(node->lchild);
        printf("%d\n",node->data);
        InOrderTree(node->rchild);
    }
}

void AfterPreOrderTree(Node node){
    if (node != NULL) {
        AfterPreOrderTree(node->lchild);
        AfterPreOrderTree(node->rchild);
        printf("%d\n",node->data);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Node node;
    TreeNode* test;
    std::cout << "Hello, World!\n";
    return 0;
}
