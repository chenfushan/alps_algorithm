//
//  main.cpp
//  MergeKList
//
//  Created by Alps on 14/12/12.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode *l1,*l2;
        l1 = (ListNode*)malloc(sizeof(struct ListNode));
        l1->next = NULL;
        l2 = l1;
        vector<ListNode *>::iterator iter;
        vector<ListNode *>::iterator temp;
        while (!lists.empty()) {
            for (temp = lists.begin(), iter = lists.begin(); iter != lists.end();) {
                if (*iter == NULL) {
                    lists.erase(iter);
                    continue;
                }
                temp = (*iter)->val < (*temp)->val?iter:temp;
                iter++;
            }
            l1->next = *temp;
            l1 = l1->next;
            *temp = (*temp)->next;
            if (*temp == NULL) {
                lists.erase(temp);
            }
        }
        
        return l2->next;
    }
};

int main(int argc, const char * argv[]) {
    vector<ListNode*> list;
    Solution sl;
    sl.mergeKLists(list);
    printf("success!");
    return 0;
}
