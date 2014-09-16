//
//  main.cpp
//  LinkListCycle_leetcode
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
    bool hasCycle(ListNode *head){
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        if (head == NULL || head->next == NULL) {
            return false;
        }
        while (temp2 != NULL && temp2->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next->next;
            if (temp1 == temp2) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

