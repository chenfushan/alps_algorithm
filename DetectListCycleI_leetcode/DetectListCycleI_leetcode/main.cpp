//
//  main.cpp
//  DetectListCycleI_leetcode
//
//  Created by Alps on 14-9-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* detectCycle(ListNode *head){
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        while (temp2 != NULL && temp2->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if (temp1 == temp2) {
                temp2 = head;
                while (temp1 != temp2) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                return temp2;
            }
        }
        return NULL;
    }
};

int main(int argc, const char * argv[])
{
    ListNode *head;
    ListNode n1 = ListNode(3);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(0);
    ListNode n4 = ListNode(-4);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = head;
    ListNode *cycle = NULL;
    Solution sl;
    cycle = sl.detectCycle(head);
    printf("%d\n",cycle->val);
    return 0;
}

