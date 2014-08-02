//
//  main.cpp
//  MergeSort
//
//  Created by Alps on 14-8-2.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int
using namespace std;

void Merge(int *A, int left, int right, int center, int *TmpArr){
    int leftPtr = left, rightPtr = center;
    int i = left;
    while (leftPtr < center && rightPtr <= right) {
        if (A[leftPtr] <= A[rightPtr]) {
            TmpArr[i++] = A[leftPtr];
            leftPtr++;
        }else{
            TmpArr[i++] = A[rightPtr];
            rightPtr++;
        }
    }
    if (leftPtr >= center) {
        while (rightPtr <= right) {
            TmpArr[i++] = A[rightPtr];
            rightPtr++;
        }
    }
    if (rightPtr > right) {
        while (leftPtr < center) {
            TmpArr[i++] = A[leftPtr];
            leftPtr++;
        }
    }
    for (int j = left; j <= right ; j++) {
        A[j] = TmpArr[j];
    }
}

void MSort(int *A, ElementType *TmpArr, int left, int right){
    
    if (left < right) {
        int center = (left+right)/2;
        MSort(A, TmpArr, left,center);
        MSort(A, TmpArr, center+1, right);
        Merge(A,left, right, center+1, TmpArr);
    }
}

void MergeSort(int *A, int length){
    ElementType TmpArr[length];
    int left = 0,right = length-1;
    MSort(A, TmpArr, left, right);
    for (int i = 0; i < length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    ElementType A[] = {24, 13, 26, 1, 2, 27, 38, 15};
    MergeSort(A, sizeof(A)/sizeof(ElementType));
    return 0;
}

