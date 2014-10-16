//
//  main.cpp
//  RemoveDuplicateList_leetcode
//
//  Created by Alps on 14-10-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *deleteDuplicates(ListNode *head){
        if (head == NULL) {
            return NULL;
        }
        int repeat = head->val;
        ListNode *node = head;
        ListNode *del;
        
        while (node->next != NULL) {
            if (node->next->val == repeat) {
                del = node->next;
                node->next = node->next->next;
                continue;
            }else{
                node = node->next;
                repeat = node->val;
            }
            
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
