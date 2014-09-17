//
//  main.cpp
//  reverseIntNum_leetcode
//
//  Created by Alps on 14-9-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    int reverse(int x){
        int s = 0;
        
        while (x != 0) {
            s =s*10 + x%10;
            x = x/10;
        }
        return s;
    }
};

int main(int argc, const char * argv[])
{
    int a = -15;
    Solution sl;
    int b = sl.reverse(a);
    printf("%d\n",b);
    return 0;
}

