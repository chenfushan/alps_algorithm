//
//  main.cpp
//  QuickSort
//
//  Created by Alps on 14-8-2.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int

void QuickSort(ElementType *A, int left, int right){
    if (left < right) {
        int i = left, j = left;
        int mid = right;
        for (int k = left; k < right; k++) {
            if (A[j] <= A[mid]) {
                A[i] += A[j];
                A[j] = A[i]-A[j];
                A[i] = A[i]-A[j];
                i++;
                j++;
            }else{
                j++;
            }
        }
        A[i] = A[i]+A[mid];
        A[mid] = A[i]-A[mid];
        A[i] = A[i]-A[mid];
        mid = i;
        QuickSort(A, left, mid-1);
        QuickSort(A, mid+1, right);
    }
    
}

int main(int argc, const char * argv[])
{
    ElementType A[] = {24, 13, 26, 1, 2, 27, 38, 15};
    int length = sizeof(A)/sizeof(ElementType);
    QuickSort(A, 0, length-1);
    for (int i = 0; i < length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

