//
//  main.cpp
//  ValidPalindrome_leetcode
//
//  Created by Alps on 14/10/23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int length = (int)s.length();
        if (length <= 1) {
            return true;
        }
        int i = 0,j = length-1;
        while (i <= j) {
            if (!((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= '0' && s[i] <= '9'))) {
                i++;
                continue;
            }
            if (!((s[j] >= 'a' && s[j] <= 'z')||(s[j] >= 'A' && s[j] <= 'Z')||(s[j] >= '0' && s[j] <= '9'))) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string s = "ab";
    Solution sl;
    sl.isPalindrome(s);
    std::cout << "Hello, World!\n";
    return 0;
}
