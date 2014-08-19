//
//  main.cpp
//  heapSort
//
//  Created by Alps on 14-8-2.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#define ElementType int
#define MinItem -1
using namespace std;




void Swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void BuildHeap(ElementType *A, int length){
    for (int i = length/2; i > 0; i--) {
        for (int j = i; j*2 <= length;) {
            if (j *2 != length) {
                if (A[j*2] > A[j*2+1] && A[j*2] > A[j]) {
                    Swap(A[j*2], A[j]);
                    j *= 2;
                }
                if (A[j*2+1] > A[j*2] && A[j*2+1] > A[j]) {
                    Swap(A[j*2+1], A[j]);
                    j = j*2+1;
                }else{
                   break;
                }
                
            }else{
                if (A[j*2] > A[j]) {
                    Swap(A[j*2], A[j]);
                    j *= 2;
                }else{
                    break;
                }
            }
        }
        
    }
}

ElementType DeleteMax(ElementType *A, int length){
    int MaxElement, LastElement;
    int i,temp;
    MaxElement = A[1];
    LastElement = A[length];
    for (i = 1; i*2 < length; i = temp) {
        temp = i*2;
        if (A[temp] > A[temp]+1) {
            A[i] = A[temp];
        }else{
            A[i] = A[temp+1];
            temp++;
        }
        if (LastElement > A[i]) {
            A[i] = LastElement;
            break;
        }
    }
    A[i] = LastElement;
    return MaxElement;
}

void HeapSort(ElementType *A, int length){
    BuildHeap(A, length);
    for (int i = 0; i < length; i++) {
        A[length-i] = DeleteMax(A, length-i);
    }
}


int main(int argc, const char * argv[])
{

    ElementType A[]={MinItem,53,26,41,59,97,31,58};
    int length = sizeof(A)/sizeof(ElementType) -1;
    HeapSort(A, length);
//    BuildHeap(A, length);
    for (int i = 1; i <= length; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}

