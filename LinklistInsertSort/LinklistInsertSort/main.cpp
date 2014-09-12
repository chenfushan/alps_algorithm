//
//  main.cpp
//  LinklistInsertSort
//
//  Created by Alps on 14-9-12.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x) , next(NULL){}
};

class Solution{
public:
    ListNode *insertionSortList(ListNode *head){
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            return head;
        }
        ListNode *tmp1 = head;
        ListNode *tmp2 = head;
        ListNode *switchNode;
        ListNode *pre;
        int flag = 0;
        for (;tmp2 != NULL && tmp2->next != NULL;) {
            for (tmp1 = head, pre = tmp1; tmp1 != tmp2->next; tmp1 = tmp1->next) {
                if (tmp2->next->val < tmp1->val) {
                    if (pre == tmp1) {
                        switchNode = tmp2->next;
                        tmp2->next = tmp2->next->next;
                        switchNode->next = tmp1;
                        head = switchNode;
                        flag = 1;
                        break;
                    }
                    switchNode = tmp2->next;
                    tmp2->next = tmp2->next->next;
                    switchNode->next = tmp1;
                    pre->next = switchNode;
                    flag = 1;
                    break;
                }
                pre = tmp1;
            }
            if (flag == 0) {
                tmp2 = tmp2->next;
            }else{
                flag = 0;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[])
{
    ListNode *head = (ListNode*)malloc(sizeof(struct ListNode));
    head->val = 4;
    ListNode *node = (ListNode*)malloc(sizeof(struct ListNode));
    node->val = 19;
    head->next = node;
    node->next = (ListNode*)malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 14;
    node->next = (ListNode*)malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 5;
    node->next = (ListNode*)malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = -3;
    node->next = NULL;
    Solution sl;
    node = sl.insertionSortList(head);
//    node = head;
    while (node) {
        printf("%d ",node->val);
        node = node->next;
    }
    
    return 0;
}

