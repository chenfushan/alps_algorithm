//
//  main.cpp
//  SortListToBST_leetcode
//
//  Created by Alps on 14-10-10.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x):val(x), right(NULL), left(NULL){}
};

class Solution{
public:
    ListNode *list;
    TreeNode *sortedListToBST(ListNode *head){
        int length = 0;
        for (length = 0,list = head; list != NULL; length++) {
            list = list->next;
        }
        list = head;
        if (length == 0) {
            return NULL;
        }
        return SortList(length);
    }
    
    TreeNode *SortList(int n){
        if (n == 0) {
            return NULL;
        }
        TreeNode *node = (TreeNode*)malloc(sizeof(struct TreeNode));
        node->left = SortList(n/2);
        node->val = list->val;
        list = list->next;
        node->right = SortList(n-n/2-1);
        return node;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
