//
//  main.cpp
//  SortLinkList
//
//  Created by Alps on 14-9-11.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode *mid = GetMid(head);
        ListNode *temp = NULL;
        if (mid != NULL) {
            temp = mid->next;
            mid->next = NULL;
        }
        head = sortList(head);
        temp = sortList(temp);
        head = MergeSort(head, temp);
        return head;
    }
    ListNode* MergeSort(ListNode *left, ListNode *right){
        if (left == NULL && right == NULL) {
            return NULL;
        }
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        ListNode *temp = NULL;
        if (left->val > right->val) {
            temp = left;
            left = right;
            right = right->next;
            left->next = temp;
        }
        ListNode * head = left;
        while (right != NULL) {
            if (right == NULL) {
                break;
            }
            if (left == NULL) {
                temp->next = right;
                break;
            }
            if (left->val < right->val) {
                temp = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
                temp->next->next = left;
                temp = temp->next;
            }
            
        }
        return head;
    }
    ListNode *GetMid(ListNode *list){
        if (list && list->next) {
            ListNode *p1 = list;
            ListNode *p2 = list->next;
            while (p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            return p1;
        }else{
            return list;
        }
    }
};

int main(int argc, const char * argv[])
{

    ListNode *head = (ListNode *)malloc(sizeof(struct ListNode));
    head->val = -84;
    ListNode *tmp1 = head;
    ListNode *tmp2 = (ListNode *)malloc(sizeof(struct ListNode));;
    tmp1->next = tmp2;
    tmp2->val = 142;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 41;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = -17;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = -71;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 170;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 186;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 183;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = -21;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = -76;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 76;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 10;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 29;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 81;
    tmp2->next = (ListNode *)malloc(sizeof(struct ListNode));
    tmp2 = tmp2->next;
    tmp2->val = 112;
    tmp2->next = NULL;
    tmp1 = head;
    while (tmp1) {
        printf("%d ",tmp1->val);
        tmp1 = tmp1->next;
    }
    printf("\n");
    Solution sl;
    head = sl.sortList(head);
    while (head) {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}

