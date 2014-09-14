//
//  main.cpp
//  PostorderTraversal_leetcode
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
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> TreeVector;
        pushTree(root, TreeVector);
        return TreeVector;
    }
    void pushTree(TreeNode *node, vector<int> &TreeVector){
        if (node == NULL) {
            return;
        }
        if (node->left != NULL) {
            pushTree(node->left, TreeVector);
        }
        if (node->right != NULL) {
            pushTree(node->right, TreeVector);
        }
        TreeVector.push_back(node->val);
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
    vector<int> vec = sl.postorderTraversal(root);
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++) {
        printf("%d ",*iter);
    }
    return 0;
}

