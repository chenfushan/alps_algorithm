//
//  main.cpp
//  BubbleSort
//
//  Created by Alps on 14-8-2.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int

void BubbleSort(int *A, int length){
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (A[j] > A[j+1]) {
                A[j] += A[j+1];
                A[j+1] = A[j]-A[j+1];
                A[j] = A[j] - A[j+1];
            }
        }
    }
}

int main(int argc, const char * argv[])
{

    ElementType A[] = {24, 13, 26, 1, 2, 27, 38, 15};
    int length = sizeof(A)/sizeof(ElementType);
    BubbleSort(A, length);
    for (int i = 0; i < length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

