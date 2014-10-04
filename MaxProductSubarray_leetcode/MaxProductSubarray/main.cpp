//
//  main.cpp
//  MaxProductSubarray
//
//  Created by Alps on 14-10-1.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

//class Solution{
//public:
//    int maxProduct(int A[], int n){
//        int max = A[0];
//        int temp = A[0];
//        int i = 0;
//        for (i = 1; i < n; i++) {
//            if (temp > max) {
//                max = temp;
//            }
//            if (temp < 0) {
//                temp = 0;
//            }
//            temp += A[i];
//        }
//        return max;
//    }
//};

/************************ this is for product add max ***********/

//class Solution{
//public:
//    int maxProduct(int A[], int n){
//        int max = A[0];
//        int temp = 1;
//        int i, j;
//        for (i = 0; i < n; i++) {
//            for (j = i; j < n; j++) {
//                temp = temp*A[j];
//                max = max > temp?max:temp;
//            }
//            temp = 1;
//        }
//        return max;
//    }
//};
//*********************** this is the right slolution, but the time complex is O(n2) *****//

//class Solution{
//public:
//    int maxProduct(int A[], int n){
//        int i,j;
//        int max = A[0];
//        int temp = 1;
//        int num = 0;
//        int end = 0, start = 0;
//        if (n == 1) {
//            return A[0];
//        }
//        for (i = 0; i < n; i++) {
//            if (A[i] < 0) {
//                num++;
//                end = i;
//            }
//        }
//        for (i = 0; i < n; i++) {
//            if (A[i] < 0) {
//                start = i;
//                break;
//            }
//        }
//        if (num%2 == 0) {
//            for (i = 0; i < n; i++) {
//                temp = temp * A[i];
//                max = max > temp?max:temp;
//            }
//            return max;
//        }
//        if (num %2 == 1) {
//            for (i = 0; i < end; i++) {
//                temp = temp * A[i];
//            }
//            max = max > temp?max:temp;
//            temp = 1;
//            for (i = start+1; i < n; i++) {
//                temp = temp * A[i];
//            }
//            max = max > temp?max:temp;
//        }
//        return max;
//    }
//};
//******************** this solution is error, because it doesn't consider the number 0 ****//

class Solution{
public:
    int maxProduct(int A[], int n){
        int max = A[0];
        int min = A[0];
        int maxProductNum = A[0];
        int maxNum = A[0],minNum = A[0];
        int i = 1;
        for (i = 1; i < n; i++) {
            max = Max(Max(maxNum*A[i], minNum*A[i]), A[i]);
            min = Min(Min(maxNum*A[i], minNum*A[i]), A[i]);
            maxProductNum = Max(max, maxProductNum);
            maxNum = max;
            minNum = min;
        }
        return maxProductNum;
    }
    int Max(int a, int b){
        return a>b?a:b;
    }
    int Min(int a, int b){
        return a<b?a:b;
    }
};

int main(int argc, const char * argv[]) {
    int A[] = {-4,-3,-2};
    Solution sl;
    int a = sl.maxProduct(A, 3);
    printf("%d\n",a);
    return 0;
}
