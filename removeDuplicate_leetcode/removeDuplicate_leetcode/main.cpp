//
//  main.cpp
//  removeDuplicate_leetcode
//
//  Created by Alps on 14/10/23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        int i,j;
        if (n < 1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        for (i = 0,j =1; j < n;j++) {
            if (A[i] == A[j]) {
                continue;
            }else{
                A[i+1] = A[j];
                i++;
            }
        }
        for (j = i+1; j < n; j++) {
            A[j] = '\0';
        }
        return i+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
