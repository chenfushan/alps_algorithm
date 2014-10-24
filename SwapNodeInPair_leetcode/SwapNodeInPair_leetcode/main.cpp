//
//  main.cpp
//  SwapNodeInPair_leetcode
//
//  Created by Alps on 14/10/24.
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
    ListNode* swapPairs(ListNode *head){
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = (ListNode*)malloc(sizeof(struct ListNode));
        newHead->next = head;
        ListNode *loop = newHead;
        ListNode *temp = loop;
        ListNode *swap;
        while (loop != NULL && loop->next != NULL && loop->next->next != NULL) {
            swap = loop->next;
            loop->next = swap->next;
            loop = loop->next;
            swap->next = loop->next;
            loop->next = swap;
            loop = loop->next;
        }
        newHead = newHead->next;
        return newHead;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
