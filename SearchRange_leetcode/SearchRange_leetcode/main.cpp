//
//  main.cpp
//  SearchRange_leetcode
//
//  Created by Alps on 15/4/15.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        vector<int> range;
        int exist = binarySearch(A, start, end, target);
        if(exist == -1){
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }
        int left = exist;
        int right = exist;
        while(left != start && A[left-1] == target){
            left = binarySearch(A, start, left-1, target);
        }
        while((right != end) && A[right+1] == target){
            right = binarySearch(A, right+1, end, target);
        }
        range.push_back(left);
        range.push_back(right);
        return range;
    }
    
    int binarySearch(int A[], int start, int end, int target){
        if(end < start){
            return -1;
        }
        int mid = (start + end)/2;
        if(target == A[mid]){
            return mid;
        }
        if(target > A[mid]){
            return binarySearch(A, mid+1, end, target);
        }else{
            return binarySearch(A, start, mid-1, target);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
