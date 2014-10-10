//
//  main.cpp
//  candy_leetcode
//
//  Created by Alps on 14-9-18.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int candy(vector<int> &ratings){
        int candy_num = 0;
        vector<int>::iterator iter;
        iter = ratings.begin();
        vector<int>::reverse_iterator riter;
        riter = ratings.rbegin();
        unsigned long int length = ratings.size();
        if (length == 0) {
            return 0;
        }
        int a[length],b[length];
        a[0] = 1;
        int i = 1;
        int prerat = *ratings.begin();
        for (++iter; iter != ratings.end(); iter++,i++) {
            if (*iter > prerat) {
                a[i] = a[i-1]+1;
            }
            if (*iter == prerat) {
                a[i] = 1;
            }
            if (*iter < prerat) {
                a[i] = 1;
            }
            prerat = *iter;
        }
        b[length-1] = 1;
        i = (int)length-2;
        prerat = *riter;
        for (++riter; riter != ratings.rend(); riter++,i--) {
            if (*riter > prerat) {
                b[i] = b[i+1]+1;
            }
            if (*riter == prerat) {
                b[i] = 1;
            }
            if (*riter < prerat) {
                b[i] = 1;
            }
            prerat = *riter;
        }
        for (i = 0; i < length; i++) {
            candy_num += Max(a[i],b[i]);
        }
        return candy_num;
    }
    int Max(int a, int b){
        return a>b?a:b;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

