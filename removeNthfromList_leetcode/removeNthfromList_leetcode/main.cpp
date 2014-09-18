//
//  main.cpp
//  removeNthfromList_leetcode
//
//  Created by Alps on 14-9-18.
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
    ListNode * removeNthFromEnd(ListNode *head, int n){
        int i = 0;
        ListNode *temp = head;
        ListNode *loop = head;
        for (i = 0; i < n; i++) {
            loop = loop->next;
        }
        if (loop == NULL) {
            head = head->next;
            free(temp);
            return head;
        }
        while (loop->next != NULL) {
            loop = loop->next;
            temp = temp->next;
        }
        ListNode *nNode = temp->next;
        temp->next = temp->next->next;
        free(nNode);
        return head;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

