//
//  main.cpp
//  AddTwoNumLinkList_leetcode
//
//  Created by Alps on 14-9-14.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        int length1 = 0, length2 = 0;
        ListNode *tmp1 = l1, *tmp2 = l2;
        int diff, i;
        while (tmp1 != NULL) {
            length1+=1;
            tmp1 = tmp1->next;
        }
        while (tmp2 != NULL) {
            length2 += 1;
            tmp2 = tmp2->next;
        }
        tmp1 = l1;
        tmp2 = l2;
        if (length1 > length2) {
            diff = length1-length2;
//            for (i = 0; i < diff; i++) {
//                tmp1 = tmp1->next;
//            }
            while (tmp1 && tmp2) {
                tmp1->val = tmp1->val + tmp2->val;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }else{
            diff = length2-length1;
//            for (i = 0; i < diff; i++) {
//                tmp2 = tmp2->next;
//            }
            while (tmp1 && tmp2) {
                tmp2->val = tmp2->val + tmp1->val;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
        }
//        ListNode * Sum = (ListNode*)malloc(sizeof(struct ListNode));
        tmp1 = l1;
        tmp2 = l2;
        ListNode * head = NULL;
        if (length1 > length2) {
//            while (tmp1 != NULL) {
//                ListNode *Sum = (ListNode *)malloc(sizeof(struct ListNode));
//                Sum->val = tmp1->val;
//                Sum->next = head;
//                head = Sum;
//                tmp1 = tmp1->next;
//            }
            head = l1;
        }else{
//            while (tmp2 != NULL) {
//                ListNode *Sum = (ListNode*)malloc(sizeof(struct ListNode));
//                Sum->val = tmp2->val;
//                Sum->next = head;
//                head = Sum;
//                tmp2 = tmp2->next;
//            }
            head = l2;
        }
        ListNode * loop = head;
        int number = 0;
        while (loop != NULL) {
            number = loop->val/10;
            loop->val = loop->val%10;
            if (number == 0) {
                loop = loop->next;
                continue;
            }
            if (number > 0 && loop->next == NULL) {
                loop->next = (ListNode *)malloc(sizeof(struct ListNode));
                loop->next->val = number;
                loop->next->next = NULL;
                break;
            }else{
                loop->next->val = loop->next->val + number;
                loop = loop->next;
            }
        }
        
        return head;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *l1 = (ListNode*)malloc(sizeof(struct ListNode));
    ListNode *l2 = (ListNode*)malloc(sizeof(struct ListNode));
    ListNode f = ListNode(8);
//    ListNode *l3 = &f;
    l1->val = 1;
    l1->next = &f;
    l2->val = 0;
    l2->next = NULL;
    Solution sl;
    ListNode *head = sl.addTwoNumbers(l1, l2);
    while (head) {
        printf("%d\n",head->val);
        head = head->next;
    }
    printf("done!\n");
    return 0;
}

