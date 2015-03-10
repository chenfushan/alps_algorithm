//
//  main.cpp
//  MinStack3_leetcode
//
//  Created by Alps on 14/12/3.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class MinStack {
public:
    
    struct StackNode{
        int num;
        StackNode *next;
    };
    typedef StackNode* stack;
    stack s;
    MinStack(){
        s = (stack)malloc(sizeof(struct StackNode));
        s->next = NULL;
    }
    
    int min;
    void push(int x) {
        if (s->next == NULL) {
            stack node = (stack)malloc(sizeof(struct StackNode));
            node->num = x;
            node->next = s->next;
            s->next = node;
            min = x;
        }else{
            stack node = (stack)malloc(sizeof(struct StackNode));
            node->num = x;
            node->next = s->next;
            s->next = node;
            if (x < min) {
                min = x;
            }
        }
    }
    
    void pop() {
        if (s->next == NULL) {
            return;
        }else{
            stack temp = s->next;
            if (min == s->next->num && s->next->next != NULL) {
                
                s->next = s->next->next;
                free(temp);
                min = s->next->num;
                for (stack loop = s->next; loop != NULL; loop = loop->next) {
                    if (min > loop->num) {
                        min = loop->num;
                    }
                }
            }else{
                
                s->next = s->next->next;
                free(temp);
            }
            
        }
    }
    
    int top() {
        if (s->next == NULL) {
            return NULL;
        }
        return s->next->num;
    }
    
    int getMin() {
        if (s->next == NULL) {
            return NULL;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    MinStack MinS;
    MinS.push(-1);
    MinS.push(0);
    MinS.push(2);
    MinS.push(-2);
    printf("%d\n",MinS.top());
    MinS.pop();
    MinS.pop();
    MinS.pop();
    printf("%d\n",MinS.getMin());
    return 0;
}
