//
//  main.cpp
//  TreeWidth
//
//  Created by Alps on 15/3/11.
//  Copyright (c) 2015年 chen. All rights reserved.
//
// achieve the binary tree width.

#include <iostream>
using namespace std;

#ifndef MAXDEEP
#define MAXDEEP 10
#endif

struct Node{
    int val;
    struct Node * right;
    struct Node * left;
    Node(int v,Node* r,Node* l): val(v), right(r), left(l) {}
};

typedef Node* Tree;

int deepth = 0;
int width[MAXDEEP] = {0};

void TreeWidth(Tree t){
    if (t == NULL) {
        return;
    }
    if (deepth == 0) {
        width[0] = 1;
    }
    if (t->left != NULL) {
        width[deepth+1] += 1;
        deepth += 1;
        TreeWidth(t->left);
    }
    if (t->right != NULL) {
        width[deepth+1] += 1;
        deepth+=1;
        TreeWidth(t->right);
    }
    deepth-=1;
}

int main(int argc, const char * argv[]) {
    Node n1(1,NULL,NULL);
    Node n2(2,NULL,NULL);
    Node n3(3,NULL,NULL);
    Node n4(4,&n1,&n2);
    Node n5(5,&n3,NULL);
    Node n6(6,&n4,&n5);
    Tree t = &n6;
    TreeWidth(t);
    for (int i = 0; i < MAXDEEP; i++) {
        printf("%d ",width[i]);
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
