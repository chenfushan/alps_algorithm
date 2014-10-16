//
//  main.cpp
//  PartitionList_leetcode
//
//  Created by Alps on 14-10-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *partition(ListNode *head, int x){
        if (head == NULL) {
            return NULL;
        }
        ListNode *node = (ListNode*)malloc(sizeof(struct ListNode));
        node->next = head;
        ListNode *xnode = node;
        while (xnode->next->val < x) {
            xnode = xnode->next;
            if (xnode->next == NULL) {
                return head;
            }
        }
        ListNode *loop = xnode;
        ListNode *temp;
        while (loop->next != NULL) {
            if (loop->next->val < x) {
                temp = loop->next;
                loop->next = loop->next->next;
                temp->next = xnode->next;
                xnode->next = temp;
                xnode = xnode->next;
                continue;
            }
            loop = loop->next;
            
        }
        temp = node;
        node = node->next;
        free(temp);
        return node;
    }
};

int main(int argc, const char * argv[]) {
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(3);
    node1.next = &node2;
    node2.next = &node3;
    ListNode *head = &node1;
    Solution sl;
    head = sl.partition(head, 3);
    return 0;
}
