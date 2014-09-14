//
//  main.cpp
//  PreorderTraversal_leetcode
//
//  Created by Alps on 14-9-14.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> vec;
        push_node(root, vec);
        return vec;
    }
    void push_node(TreeNode *node, vector<int> &vec){
        if (node == NULL) {
            return;
        }
        vec.push_back(node->val);
        push_node(node->left, vec);
        push_node(node->right, vec);
        
    }
};

int main(int argc, const char * argv[])
{
    TreeNode *root;
    TreeNode temp = TreeNode(1);
    root = &temp;
    //    printf("%d\n",root->val);
    TreeNode temp2 = TreeNode(2);
    root->right = &temp2;
    TreeNode temp3 = TreeNode(3);
    root->right->left = &temp3;
    Solution sl;
    vector<int> vec = sl.preorderTraversal(root);
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        printf("%d ",*iter);
    }
    return 0;
}

