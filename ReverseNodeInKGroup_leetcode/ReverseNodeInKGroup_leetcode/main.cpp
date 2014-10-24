//
//  main.cpp
//  ReverseNodeInKGroup_leetcode
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
    ListNode * reverseKGroup(ListNode *head, int k){
        ListNode *loop = head;
        if (k <= 1) {
            return head;
        }
        int length = 0;
        while (loop != NULL) {
            loop = loop->next;
            length++;
        }
        if (length <= 1) {
            return head;
        }
        int repeat = length/k;
        if (repeat == 0) {
            return head;
        }
        int i = repeat,j = 1;
        ListNode *newhead = (ListNode*)malloc(sizeof(struct ListNode));
        newhead->next = head;
        ListNode *khead = newhead;
        loop = head;
        while (loop != NULL && loop->next != NULL) {
            if (j < k) {
                SwitchNode(khead, loop);
                j++;
            }else{
                khead = loop;
                j = 1;
                loop = loop->next;
                i--;
                if (i <= 0) {
                    break;
                }
            }
        }
        newhead = newhead->next;
        return newhead;
    }
    ListNode * SwitchNode(ListNode *head, ListNode *tail){
        ListNode *temp = head->next;
        head->next = tail->next;
        tail->next = tail->next->next;
        head->next->next = temp;
        return tail;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
