//
//  main.cpp
//  RadixSort
//
//  Created by Alps on 14-7-26.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include "cmath"

using namespace std;

int LoopTimes(int Num){
    int times = 0;
    
    while (Num) {
        Num = Num/10;
        times++;
    }
    
    return times;
}

void Sort(int *A, int times, int N);

void RadixSort(int * A, int Max, int N){
    int i = 0;
    int times = LoopTimes(Max);
    for (i = 0; i < times; i ++) {
        Sort(A, i, N);
    }
}

void Sort(int *A, int times, int N){
    int i = 0,k = 0,h = 0,j = 0;
    int remainder;
    int tmp[10][N];
    memset(tmp, '\0', 10*N*sizeof(int));
    for (k = 0; k < N; k++) {
        remainder = (A[k]/(int)pow(10, times))%10;
        while (tmp[remainder][h] != '\0') {
            h++;
        }
        tmp[remainder][h] = A[k];
        h = 0;
    }
    h = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < N; j++) {
            if (tmp[i][j] != '\0') {
                A[h] = tmp[i][j];
                h++;
            }
        }
    }
}



int main(int argc, const char * argv[])
{

    int A[]={4, 2, 6, 1, 13, 532, 67, 134, 132, 543};
    int N = sizeof(A)/sizeof(int);
    int Max = 543;
    int i = 0;
//    printf("%d\n",N);
    RadixSort(A, Max, N);
//    printf("%d\n",(int)pow(10, 0));
    for (i = 0; i < N; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

