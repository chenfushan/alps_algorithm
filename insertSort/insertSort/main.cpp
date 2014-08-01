//
//  main.cpp
//  insertSort
//
//  Created by Alps on 14-8-1.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

void insertSort(int *A, int length){
    int i = 0,j = 0;
    for (i = 0; i < length; i++) {
        int tmp = A[i];
        for (j = i; j > 0 && A[j-1] > tmp; j--) {
            A[j] = A[j-1];
        }
        A[j] = tmp;
    }
}

int main(int argc, const char * argv[])
{
    int A[] = {34,8,64,51,32,21};
    int length = sizeof(A)/sizeof(int);
    insertSort(A, length);
    for (int i = 0; i < length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

