//
//  main.cpp
//  MergeList
//
//  Created by Alps on 14/12/6.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode *sortList(ListNode* head){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* right = NULL;
        if (mid != NULL) {
            right = mid->next;
            mid->next = NULL;
        }
        head = sortList(head);
        right = sortList(right);
        head = MergeList(head, right);
        return head;
    }
    
    ListNode* getMid(ListNode* node){
        if (node == NULL || node->next == NULL) {
            return node;
        }
        ListNode* l1 = node;
        ListNode* l2 = node->next;
        while (l2 && l2->next) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        return l1;
    }
    
    ListNode* MergeList(ListNode* left, ListNode* right){
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        ListNode* temp = NULL;
        if (left->val >= right->val) {
            temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }
        left->next = MergeList(left->next, right);
        return left;
    }
};

int main(int argc, const char * argv[]) {
    Solution sl;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    sl.sortList(head);
    return 0;
}
