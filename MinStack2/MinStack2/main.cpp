//
//  main.cpp
//  MinStack2
//
//  Created by Alps on 14/12/3.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class MinStack {
public:
    vector<int> stack;
    int min;
    void push(int x) {
        if (stack.empty()) {
            stack.push_back(0);
            min = x;
        }else{
            stack.push_back(x-min);
            if (x < min) {
                min = x;
            }
        }
        
    }
    
    void pop() {
        if (stack.empty()) {
            return;
        }else{
            if (stack.back() < 0) {
                min = min - stack.back();
            }
            stack.pop_back();
        }
    }
    
    int top() {
        if (stack.empty()) {
            return NULL;
        }
        if (stack.back() > 0) {
            return stack.back()+min;
        }else{
            return min;
        }
    }
    
    int getMin() {
        if (stack.empty()) {
            return NULL;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
