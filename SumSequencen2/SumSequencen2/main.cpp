//
//  main.cpp
//  SumSequencen2
//
//  Created by Alps on 14-7-23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

int MaxSubSequenceSum(const int A[], int N){
    int MaxSum, ThisSum, i, j;
    MaxSum = 0;
    for (i = 0; i < N; i++) {
        ThisSum = 0;
        for (j = i; j < N; j++) {
            ThisSum += A[j];
            MaxSum = MaxSum > ThisSum ? MaxSum : ThisSum;
        }
    }
    return MaxSum;
}

int main(int argc, const char * argv[])
{
    int A[] = {1, 2, -5, 2, 5, 1, 8, -4};
    int N = sizeof(A)/sizeof(int);
    //    printf("%d\n",N);
    int MaxSum = MaxSubSequenceSum(A, N);
    printf("%d\n",MaxSum);
    
    return 0;
}

