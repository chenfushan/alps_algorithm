//
//  main.cpp
//  Find_K_Max_Number
//
//  Created by Alps on 15/10/23.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int RandNum(int start, int end);

void SwapArr(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

int FindNum(int start, int end, int * arr, int k){
    if (end <= start) {
        return arr[end];
    }
    int cur = RandNum(start, end);
    SwapArr(arr[cur], arr[end]);
    int i = start, j = start;
    for (i = start; i < end; ++i) {
        if (arr[i] < arr[end]) {
            SwapArr(arr[i], arr[j]);
            j++;
        }
    }
    SwapArr(arr[j], arr[end]);
    if (j == k-1) {
        return arr[j];
    }else if (j > k-1) {
        return FindNum(start, j-1, arr, k);
    }else {
        return FindNum(j+1, end, arr, k);
    }
}


int RandNum(int start, int end){
    if ((end-start) == 0 || end < start) {
        return 0;
    }
    srand((unsigned)time(NULL));
    int TEMP_RAND_NUM = rand()%(end-start) + start;
    return TEMP_RAND_NUM;
}

int FindKMax(int * arr, int length, int k){
    return FindNum(0, length-1, arr, k);
    return 0;
}

int main(int argc, const char * argv[]) {
    int a[5] = {4,2,1,3,5};
    printf("%d\n",FindKMax(a, 5, 3));
    return 0;
}
