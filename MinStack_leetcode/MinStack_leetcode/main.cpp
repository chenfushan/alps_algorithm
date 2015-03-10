//
//  main.cpp
//  MinStack_leetcode
//
//  Created by Alps on 14/12/2.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

class MinStack {
public:
    struct StackNode{
        int num;
        int min;
    };
    vector<StackNode> stack;
    void push(int x) {
        if (stack.empty()) {
            StackNode S = {x,x};
            stack.push_back(S);
        }else{
            if (x < stack.back().min) {
                StackNode S = {x,x};
                stack.push_back(S);
            }else{
                StackNode S = {x,stack.back().min};
                stack.push_back(S);
            }
        }
        
    }
    
    void pop() {
        if (stack.empty()) {
            
        }else{
            stack.pop_back();
        }
    }
    
    int top() {
        if (stack.empty()) {
            return NULL;
        }
        return stack.back().num;
    }
    
    int getMin() {
        if (stack.empty()) {
            return NULL;
        }
        return stack.back().min;
    }
};

int main(int argc, const char * argv[]) {
    MinStack minstack;
    minstack.push(-1);
    minstack.push(1);
    printf("%d %d\n",minstack.top(), minstack.getMin());
    return 0;
}
