//
//  main.cpp
//  RemoveElementFromArray_leetcode
//
//  Created by Alps on 14/10/23.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i, j;
        if (n == 0) {
            return 0;
        }
        for (i = 0, j = n-1; j >= 0; ) {
            if (A[j] == elem) {
                A[j] = '\0';
                j--;
                continue;
            }
            if (A[i] == elem) {
                A[i] = A[j];
                A[j] = '\0';
                i++;
                j--;
            }else{
                i++;
            }
            if (i > j) {
                break;
            }
        }
        return j+1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
