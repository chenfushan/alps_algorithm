//
//  main.cpp
//  CompareVersion_leetcode
//
//  Created by Alps on 14/12/21.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = (int)version1.find(".");
        int pos2 = (int)version2.find(".");
        int start1 = 0, start2 = 0;
        string digdit1, decimal1,digdit2,decimal2;
        int dig1,dig2;
        while (pos1 != -1 && pos2 != -1) {
            digdit1 = version1.substr(start1,pos1);
            digdit2 = version2.substr(start2,pos2);
            dig1 = atoi(digdit1.c_str());
            dig2 = atoi(digdit2.c_str());
            if (compare(dig1, dig2)) {
                return compare(dig1, dig2);
            }else{
                start1 = pos1+1;
                start2 = pos2+1;
                pos1 = (int)version1.find(".",start1);
                pos2 = (int)version2.find(".",start2);
            }
        }
        
        digdit1 = version1.substr(start1);
        digdit2 = version2.substr(start2);
        dig1 = atoi(digdit1.c_str());
        dig2 = atoi(digdit2.c_str());
        
        if (pos1 == -1 && pos2 != -1) {
            if (compare(dig1, dig2)) {
                return compare(dig1, dig2);
            }else{
                digdit2 = version2.substr(pos2+1);
                dig2 = atoi(digdit2.c_str());
                if (dig2) {
                    return -1;
                }else{
                    return 0;
                }
            }
        }
        
        if (pos1 != -1 && pos2 == -1) {
            if (compare(dig1, dig2)) {
                return compare(dig1, dig2);
            }else{
                digdit1 = version1.substr(pos1+1);
                dig1 = atoi(digdit1.c_str());
                if (dig1) {
                    return 1;
                }else{
                    return 0;
                }
            }
        }
        
        if (pos1 == -1 && pos2 == -1) {
            return compare(dig1, dig2);
        }
        return 0;
    }
    
    int compare(int a, int b){
        if (a > b) {
            return 1;
        }
        if (a < b) {
            return -1;
        }
        if (a == b) {
            return 0;
        }
        return 0;
    }
};



int main(int argc, const char * argv[]) {
    string ver1 = "1.1.0";
    string ver2 = "1.1";
    Solution sl;
    printf("%d\n",sl.compareVersion(ver1, ver2));
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
