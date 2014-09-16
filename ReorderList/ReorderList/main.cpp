//
//  main.cpp
//  ReorderList
//
//  Created by Alps on 14-9-15.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    void reorderList(ListNode *head){
        int length = 0;
        ListNode *loop = head;
        while (loop != NULL) {
            length += 1;
            loop = loop->next;
        }
        if (length <= 2) {
            return;
        }
        loop = head;
        ListNode *mid;
        for (int i = 0; i < length/2; i++) {
            loop = loop->next;
        }
        mid = loop->next;
        loop->next = NULL;
        mid = reverseList(mid);
        mergeListNode(head, mid);
    }
    
    void mergeListNode(ListNode *head, ListNode *mid){
        ListNode *temp1 = head;
        ListNode *temp2;
        while (mid != NULL) {
            temp2 = temp1->next;
            temp1->next = mid;
            mid = mid->next;
            temp1->next->next = temp2;
            temp1 = temp1->next->next;
        }
    }
    
    ListNode * reverseList(ListNode *head){
        ListNode *temp = head;
        ListNode *temphead = NULL;
        while (temp != NULL) {
            head = head->next;
            temp->next = temphead;
            temphead = temp;
            temp = head;
        }
        head = temphead;
        return head;
    }
};

int main(int argc, const char * argv[])
{
    ListNode *head;
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
//    while (head) {
//        printf("%d\n",head->val);
//        head = head->next;
//    }
    Solution sl;
    sl.reorderList(head);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }

    return 0;
}

