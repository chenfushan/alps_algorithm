//
//  main.cpp
//  MinStack4_leetcode
//
//  Created by Alps on 14/12/3.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
    stack<long> s;
    long min;
    void push(int x){
        if (s.empty()) {
            s.push(0);
            min = x;
        }else{
            s.push(x-min);
            if (x < min) {
                min = x;
            }
        }
    }
    
    void pop(){
        if (s.empty()) {
            return;
        }else{
            if (s.top() < 0) {
                min = min - s.top();
            }
            s.pop();
        }
    }
    
    int top(){
        if (s.empty()) {
            return NULL;
        }else{
            if (s.top() > 0) {
                return (int)(min+s.top());
            }else{
                return (int)min;
            }
        }
    }
    
    int getMin(){
        if (s.empty()) {
            return NULL;
        }else{
            return (int)min;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    int a = -2147483648;
    
    MinStack M;
    M.push(2147483646);
    M.push(2147483646);
    M.push(2147483647);
    printf("%d\n",M.top());
    M.pop();
    printf("%d\n",M.getMin());
    M.pop();
    printf("%d\n",M.getMin());
    M.pop();
    M.push(2147483647);
    printf("%d\n",M.top());
    printf("%d\n",M.getMin());
    M.push(a);
    printf("%d\n",M.top());
    printf("%d\n",M.getMin());
    M.pop();
    printf("%d\n",M.getMin());
    return 0;
}
