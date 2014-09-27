//
//  main.cpp
//  CopyRandomList_leetcode
//
//  Created by Alps on 14-9-26.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

class Solution{
public:
    RandomListNode * copyRandomList(RandomListNode *head){
        RandomListNode *node;
        RandomListNode *loop = head;
        if (loop == NULL) {
            return  NULL;
        }
        while (loop != NULL) {
            node = (RandomListNode*)malloc(sizeof(struct RandomListNode));
            node->label = loop->label;
            node->next = loop->next;
            node->random = NULL;
            loop->next = node;
            loop = node->next;
        }
        loop = head;
        while (loop != NULL) {
            if (loop->random != NULL) {
                loop->next->random = loop->random->next;
            }
            loop = loop->next->next;
        }
        RandomListNode *copy = head->next;
        loop = head;
        node = head->next;
        while (loop != NULL && node->next != NULL) {
            loop->next = loop->next->next;
            node->next = node->next->next;
            loop = loop->next;
            node = node->next;
        }
        loop->next = NULL;
        return copy;
    }
    
};

void print(RandomListNode *head){
    RandomListNode *loop = head;
    while (loop != NULL) {
        printf("%d ",loop->label);
        loop = loop->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    RandomListNode * head;
    RandomListNode node1 = RandomListNode(1);
    RandomListNode node2 = RandomListNode(1);
    node1.next = &node2;
    head = &node1;
    Solution sl;
    RandomListNode *copy = sl.copyRandomList(head);
    print(head);
    print(copy);
    return 0;
}
