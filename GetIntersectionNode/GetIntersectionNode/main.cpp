//
//  main.cpp
//  GetIntersectionNode
//
//  Created by Alps on 14/12/12.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0;
        int length2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1) {
            temp1 = temp1->next;
            length1++;
        }
        temp2 = headB;
        while (temp2) {
            temp2 = temp2->next;
            length2++;
        }
        if (length1 == 0 || length2 == 0) {
            return NULL;
        }
        
        int sub = length1>length2?length1-length2:length2-length1;
        temp1 = headA;
        temp2 = headB;
        if (length1 >= length2) {
            for (int i = 0; i < sub; i++) {
                temp1 = temp1->next;
            }
        }else{
            for (int i = 0; i < sub; i++) {
                temp2 = temp2->next;
            }
        }
        while (temp1 && temp2) {
            if (temp1 == temp2) {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
