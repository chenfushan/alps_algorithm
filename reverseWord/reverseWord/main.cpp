//
//  main.cpp
//  reverseWord
//
//  Created by Alps on 14-9-9.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "string.h"
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string tmp = s;
        int i,j,k;
        int length = (int)s.length();
        k = length-1;
        int flag;
//        printf("%s\n",tmp.c_str());
        for (i = 0,j = 0; i < length; i++) {
            if (tmp[i] == ' ') {
                s.erase(k--);
                continue;
            }else{
                s[j++] = tmp[i];
                if (tmp[i+1] == ' ') {
                    s[j++] = ' ';
                    i++;
                }
            }
        }
        if (s[j-1] == ' ') {
            s.erase(j-1);
            j = j-1;
        }
//        printf("%s\n",s.c_str());
//        printf("%s\n",tmp.c_str());
        length = j;
        k = j-1;
        tmp = s.c_str();
//        printf("%s\n",tmp.c_str());
//        printf("%d\n",length);
        for (i = 0,j = 0; i < length; i++) {
            if (tmp[i] == ' ') {
                flag = i-1;
                while (flag >= j) {
                    s[k--] = tmp[flag];
                    flag--;
                }
                j=i+1;
                s[k--] = ' ';
            }else
            if (i == length-1) {
                flag = i;
                while (flag >= j) {
                    s[k--] = tmp[flag];
                    flag--;
                }
                j=i+1;
                s[k--] = ' ';
            }
        }
    }
};

int main(int argc, const char * argv[])
{

    string s="   a   b ";
    Solution so;
    so.reverseWords(s);
    printf("%s\n",s.c_str());
    
    return 0;
}

