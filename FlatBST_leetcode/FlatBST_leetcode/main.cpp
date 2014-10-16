//
//  main.cpp
//  FlatBST_leetcode
//
//  Created by Alps on 14-10-15.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    void flatten(TreeNode *root){
        flat(root);
    }
    
    TreeNode *flat(TreeNode *node){
        if (node == NULL) {
            return NULL;
        }
        if (node->right == NULL && node->left == NULL) {
            return node;
        }
        TreeNode *n = node->right;
        node->right = flat(node->left);
        node->left = NULL;
        TreeNode *temp = node;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->right = flat(n);
        return node;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
