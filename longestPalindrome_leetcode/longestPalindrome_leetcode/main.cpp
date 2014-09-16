//
//  main.cpp
//  longestPalindrome_leetcode
//
//  Created by Alps on 14-9-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        int i = 0;
        int max = 1;
        int temp = 0;
        int temp1 = 1;
        string result = s.substr(0,1);
        for (i = 0; i < s.length(); i++) {
            while (s[i-temp/2] == s[i+1+temp/2]) {
                temp += 2;
            }
            while (s[i-temp1/2] == s[i+2+temp1/2]) {
                temp1 += 2;
            }
            temp = temp>temp1?temp:temp1;
            if (temp > max) {
                max = temp;
                result = s.substr(i-temp/2+1, max);
            }
            temp = 0;
            temp1 = 1;
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{
    string s = "aaaaaaaaabcacbagv";
//    string tem = s.substr(0,1);
    Solution sl;
    string temp = sl.longestPalindrome(s);
    printf("%s\n",temp.c_str());
    return 0;
}

