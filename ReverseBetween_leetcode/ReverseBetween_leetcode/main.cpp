//
//  main.cpp
//  ReverseBetween_leetcode
//
//  Created by Alps on 14-10-15.
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
    ListNode *reverseBetween(ListNode *head, int m, int n){
        ListNode *node = (ListNode *)malloc(sizeof(struct ListNode));
        node->next = head;
        ListNode *headnode = node;
        ListNode *mnode = NULL, *nnode = NULL;
        ListNode *tailnode = NULL;
        ListNode *tempnode;
        int i = 1;
        int length = 0;
        while (node != NULL) {
            length++;
            node = node->next;
        }
        node = headnode;
//        if (m < 1 || n > length-1) {
//            return head;
//        }
        m++;
        n++;
        for (i = 1; i <= length; i++) {
            if (i+1 == m) {
                mnode = node;
            }
            if (i == m) {
                tailnode = node;
            }
            if (i == n) {
                nnode = node;
                node = node->next;
                tempnode = mnode->next;
                mnode->next = nnode;
                nnode->next = tempnode;
                tailnode->next = node;
                break;
            }
            if (i > m) {
                nnode = node;
                node = node->next;
                tempnode = mnode->next;
                mnode->next = nnode;
                nnode->next = tempnode;
                continue;
            }
            node = node->next;
        }
        node = headnode;
        headnode = headnode->next;
        free(node);
        return headnode;
    }
};

int main(int argc, const char * argv[]) {
    ListNode head = ListNode(3);
    ListNode *root = &head;
    ListNode n2 = ListNode(5);
    head.next = &n2;
    Solution sl;
    ListNode *node = sl.reverseBetween(root, 1, 2);
    printf("%d\n",node->next->val);
    return 0;
}
