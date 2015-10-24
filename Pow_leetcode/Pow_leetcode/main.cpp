//
//  main.cpp
//  Pow_leetcode
//
//  Created by Alps on 15/4/16.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        double result = 1;
        long  count = 1;
        int nSymbol = 0;
        if(n < 0){
            nSymbol = 1;
            n = -n;
        }
        if(n == 0 && x != 0){
            return 1;
        }
        if(x == 0 && n != 0){
            return 0;
        }
        if(x == 1){
            return 1;
        }
        while(count <= n){
            if((count & n) == count){
                result = result * x;
            }
            count = count << 1;
            x *= x;
        }
        
        if(nSymbol == 1){
            return 1/result;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution sl;
    printf("%lf\n",sl.pow(8.95371, 3));
    return 0;
}
