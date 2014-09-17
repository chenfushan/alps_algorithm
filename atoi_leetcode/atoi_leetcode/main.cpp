//
//  main.cpp
//  atoi_leetcode
//
//  Created by Alps on 14-9-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

//class Solution{
//public:
//    int atoi(const char *str){
//        int i = 0;
//        bool flag= true;
//        bool decimal = false;
//        float result = 0;
//        int del = 1;
//        for (i = 0; str[i] != '\0'; i++) {
//            if (str[i] == ' ') {
//                continue;
//            }
//            if (str[i] == '-') {
//                flag = false;
//                continue;
//            }
//            if (str[i] == '.') {
//                decimal = true;
//                del = 10;
//                continue;
//            }
//            if (str[i] >= '0' && str[i] <= '9') {
//                if (decimal == false) {
//                    result = result*10 + (int)(str[i]-'0');
//                }else{
//                    result = result + (float)((str[i]-'0')/del);
//                    del *= 10;
//                }
//            }
//        }
//        if (flag == false) {
//            result = -result;
//        }
//        return result;
//    }
//};
//*********************** this is like atof *****************// can't be accept;

class Solution{
public:
    int atoi(const char *str){
        int i = 0;
        bool flag = true;
        bool lock = false;
        int result = 0;
        for (i = 0; str[i] != '\0'; i++) {
            if (lock == false) {
                if (str[i] == ' ') {
                    continue;
                }
                if (str[i] == '-') {
                    flag = false;
                    lock = true;
                    continue;
                }
                if (str[i] == '+') {
                    lock = true;
                    continue;
                }
                if (str[i] >= '0' && str[i] <= '9'){
                    lock = true;
                }
            }
            if (str[i] >= '0' && str[i] <= '9') {
                if (result > 214748364) {
                    if (flag == true) {
                       result = 2147483647;
                    }else{
                       result = -2147483648;
                        flag = true;
                    }
                    
                    break;
                }
                if (result == 214748364) {
                    if ((int)(str[i]-'0') >= 7 && flag == true) {
                       result = 2147483647;
                        break;
                    }
                    if ((int)(str[i]-'0') >= 8 && flag == false) {
                        result = -2147483648;
                        flag = true;
                        break;
                    }
                }
                result = result*10 + (int)(str[i]-'0');
            }else{
                break;
            }
        }
        if (flag == false) {
            result = -result;
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{
    char *s = "-2147483649";
    Solution sl;
    int a = sl.atoi(s);
//    int a = atoi(s);
    printf("%d\n",a);
    return 0;
}

