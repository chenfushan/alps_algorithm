//
//  main.cpp
//  binarySearch
//
//  Created by Alps on 14-7-24.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

int binarySearch(const int A[], int X, int N){
    int start = 0, end = 0, mid;
    end = N;
    while (start <= end) {
        mid = (start + end)/2;
        if (X > A[mid]) {
            start = mid+1;
            continue;
        }else if (X < A[mid]){
            end = mid-1;
            continue;
        }else{
            return mid;
        }
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    int A[]={1 ,4 , 6, 8, 19, 34, 93};
    int N = sizeof(A)/sizeof(int);
    int X = 19;
    
    int locate = binarySearch(A, X, N);
    if (locate == -1) {
        printf("Can't find the element %d\n",X);
    }else{
        printf("The element %d is locate in %d\n",X,locate);
    }
    
    return 0;
}

