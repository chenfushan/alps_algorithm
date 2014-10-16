//
//  main.cpp
//  MergeSortList_leetcode
//
//  Created by Alps on 14-10-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = (ListNode *)malloc(sizeof(struct ListNode));
        ListNode *node = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }else{
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            }
        }
        if(l1 != NULL) {
            node->next = l1;
        }
        if (l2 != NULL) {
            node->next = l2;
        }
        node = head;
        head = head->next;
        free(node);
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
