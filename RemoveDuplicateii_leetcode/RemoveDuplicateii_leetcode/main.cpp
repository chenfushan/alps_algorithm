//
//  main.cpp
//  RemoveDuplicateii_leetcode
//
//  Created by Alps on 14-10-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        ListNode *node = (ListNode*)malloc(sizeof(struct ListNode));
        node->next = head;
        ListNode *newhead = node;
        ListNode *temp;
        int repeat;
        while (node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                repeat = node->next->val;
                while (node->next->val == repeat) {
                    temp = node->next;
                    node->next = node->next->next;
                    free(temp);
                    if (node->next == NULL) {
                        break;
                    }
                }
                continue;
            }
            node = node->next;
        }
        temp = newhead;
        newhead = newhead->next;
        free(temp);
        return newhead;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 =new ListNode(1);
//    ListNode *head = &node1;
    delete node1;
    return 0;
}
