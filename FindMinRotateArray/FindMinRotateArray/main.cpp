//
//  main.cpp
//  FindMinRotateArray
//
//  Created by Alps on 14/11/30.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

class Solution{
public:
    int findMin(vector<int> &num){
        vector<int>::iterator iter;
        int min = *num.begin();
        for (iter = num.begin(); iter != num.end(); iter++) {
            if (*iter < min) {
                return *iter;
            }
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
