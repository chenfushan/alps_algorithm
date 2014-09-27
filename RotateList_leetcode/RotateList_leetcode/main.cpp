//
//  main.cpp
//  RotateList_leetcode
//
//  Created by Alps on 14-9-27.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head, int k){
        
        if (head == NULL) {
            return NULL;
        }
        if (k == 0) {
            return head;
        }
        int length = 0;
        ListNode *loop = head;
        while (loop != NULL) {
            length++;
            loop = loop->next;
        }
        if (length == k) {
            return head;
        }
        if (length < k) {
            k = k%length;
        }
        
        ListNode *node1,*node2 = head;
        int key = 0;
        node1 = head;
        while (node1->next != NULL) {
            key++;
            if (key > k) {
                node2 = node2->next;
            }
            node1 = node1->next;
        }
        node1->next = head;
        head = node2->next;
        node2->next = NULL;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *head;
    ListNode node1(1);
    head = &node1;
    Solution sl;
    head = sl.rotateRight(head, 1);
    printf("%d\n",head->val);
    return 0;
}
