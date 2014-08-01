//
//  main.cpp
//  shellSort
//
//  Created by Alps on 14-8-1.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

void shellSort(int *A, int length){
    int i = 0;
    int j = 0;
    for (int increment = length/2; increment > 0; increment /=2) {
        for (i = increment; i < length; i++) {
            int tmp = A[i];
            for (j = i; j >= increment; j-=increment) {
                if (tmp < A[j - increment]) {
                    A[j] = A[j-increment];
                }else{
                    break;
                }
            }
            A[j] = tmp;
        }
    }
}

int main(int argc, const char * argv[])
{

    int A[]={81,94,11,96,12,35,17,95,28,58,41,75,15};
    int length = sizeof(A)/sizeof(int);
    shellSort(A, length);
    for (int i = 0; i < length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

