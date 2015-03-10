//
//  main.cpp
//  MaximumGap1_leetcode
//
//  Created by Alps on 14/12/21.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maximumGap(vector<int> &num) {
        sort(num.begin(), num.end());
        if (num.size() < 2) {
            return 0;
        }
        vector<int>::iterator iter;
        int min;
        min = num[0];
        int maxSub = 0;
        for (iter = num.begin(); iter != num.end(); iter++) {
            maxSub = maxSub > (*iter-min) ? maxSub : (*iter-min);
            min = *iter;
        }
        return maxSub;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
