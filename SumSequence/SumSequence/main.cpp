//
//  main.cpp
//  SumSequence
//
//  Created by Alps on 14-7-23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

int MaxSubsequenceSum(const int A[], int N){
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for(i = 0; i < N; i++){
        for(j = i; j < N; j++){
            ThisSum = 0;
            for (k = i; k < j; k++) {
                ThisSum += A[k];
            }
            MaxSum = ThisSum > MaxSum ? ThisSum: MaxSum;
        }
    }
    return MaxSum;
}

int main(int argc, const char * argv[])
{

    int A[] = {1, 2, -5, 2, 5, 1, 8, -4};
    int N = sizeof(A)/sizeof(int);
//    printf("%d\n",N);
    int MaxSum = MaxSubsequenceSum(A, N);
    printf("%d\n",MaxSum);
    return 0;
}

