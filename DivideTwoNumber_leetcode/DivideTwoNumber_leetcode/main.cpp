//
//  main.cpp
//  DivideTwoNumber_leetcode
//
//  Created by Alps on 15/4/15.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int divideResultSymbol = 1;
        long divisorLongArr[32];
        long divisorLongCount[32];
        long result = 0;
        long dividendLong = (long)dividend;
        long divisorLong = (long)divisor;
        if(divisorLong == 0){
            return 2147483647;
        }
        if((abs(dividendLong) < abs(divisorLong)) || dividendLong == 0){
            return 0;
        }
        if((dividendLong < 0 && divisorLong > 0) || (dividendLong > 0 && divisorLong < 0)){
            divideResultSymbol = -1;
        }
        dividendLong = abs(dividendLong);
        divisorLong = abs(divisorLong);
        divisorLongCount[0] = 1;
        for(int i = 1; i < 32; i++){
            divisorLongCount[i] = divisorLongCount[i-1] + divisorLongCount[i-1];
        }
        divisorLongArr[0] = divisorLong;
        int i = 0;
        for(i = 1; i < 32; i++){
            divisorLongArr[i] = divisorLongArr[i-1] + divisorLongArr[i-1];
            if(divisorLongArr[i] >  dividendLong || divisorLongArr[i] < 0){
                i-=1;
                break;
            }
            if (i == 31) {
                break;
            }
        }
        while(dividendLong >= divisorLongArr[i]){
            dividendLong -= divisorLongArr[i];
            result += divisorLongCount[i];
            while(dividendLong < divisorLongArr[i]){
                i -= 1;
                if (i < 0) {
                    break;
                }
            }
        }
        if (result > 2147483647 && divideResultSymbol == 1) {
            return 2147483647;
        }
        return (int)(result * divideResultSymbol);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sl;
    printf("%d\n",sl.divide(-2147483648, -1));
    std::cout << "Hello, World!\n";
    return 0;
}
