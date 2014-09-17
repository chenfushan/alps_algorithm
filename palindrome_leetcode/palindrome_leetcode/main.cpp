//
//  main.cpp
//  palindrome_leetcode
//
//  Created by Alps on 14-9-18.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPalindrome(int x){
        if (x < 0) {
            return false;
        }
        int s = 0;
        int temp = x;
        while (temp != 0) {
            s = s*10 + temp%10;
            temp = temp/10;
        }
        if (s == x) {
            return true;
        }else{
            return false;
        }
    }
};

int main(int argc, const char * argv[])
{
    int a = 1;
    Solution sl;
    bool is = sl.isPalindrome(a);
    printf("%d\n",is);
    return 0;
}

