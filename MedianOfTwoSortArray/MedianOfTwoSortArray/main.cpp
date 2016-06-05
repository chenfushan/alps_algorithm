//
//  main.cpp
//  MedianOfTwoSortArray
//
//  Created by Alps on 15/11/2.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = (int)nums1.size();
        int length2 = (int)nums2.size();
        
        if (length1 == 0) {
            if (length2 %2 == 0) {
                return (double)(nums2[length2/2]+nums2[length2/2 - 1])/2;
            }else{
                return (double)nums2[length2/2];
            }
        }
        if (length2 == 0) {
            if (length1 %2 == 0) {
                return (double)(nums1[length1/2]+nums1[length1/2 - 1])/2;
            }else{
                return (double)nums1[length1/2];
            }
        }
        
        if (length1 <= length2) {
            return findMedian(nums1, 0, length1-1, nums2, 0, length2-1);
        }else{
            return findMedian(nums2, 0, length2-1, nums1, 0, length1-1);
        }
        
        
    }
    
    int minNumber(int a, int b){
        return a < b ? a : b;
    }
    
    double findMedian(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2){
        
        if (start1 == end1 && start2 == end2) {
            return ((double)nums1[0]+(double)nums2[0])/2;
        }
        int offset = 0;
        int median1 = (start1 + end1)/2;
        int median2 = (start2 + end2)/2;
        
        if (start1 == end1 && start2 != end2) {
            if ((end2 - start2) % 2 == 0) {
                if (nums1[start1] >= nums2[median2-1] && nums1[start1] <= nums2[median2+1]) {
                    return (double)(nums1[start1]+nums2[median2])/2;
                }else if(nums1[start1] < nums2[median2-1]){
                    return (double)(nums2[median2-1] + nums2[median2])/2;
                }else{
                    return (double)(nums2[median2] + nums2[median2+1])/2;
                }
            }else{
                if (nums1[start1] >= nums2[median2] && nums1[start1] <= nums2[median2+1]) {
                    return (double)nums1[start1];
                }else if(nums1[start1] < nums2[median2]){
                    return (double)nums2[median2];
                }else{
                    return (double)nums2[median2+1];
                }
            }
            
        }
        
        if (nums1[median1] == nums2[median2]) {
            if ((nums1.size() + nums2.size())%2 != 0 || end1-start1 % 2 == 0) {
                return nums1[median1];
            }else{
                return (double)(nums1[median1]+minNumber(nums1[median1+1] , nums2[median2+1]))/2;
            }
            
        }else if (nums1[median1] < nums2[median2]){
            if (median1 == start1) {
                if ((nums1.size() + nums2.size())%2 == 0) {
                    if (nums1[start1+1] >= nums2[median2+1]) {
                        return (double)(nums2[median2]+nums2[median2+1])/2;
                    }else if(median2 != 0 && nums1[start1+1] <= nums2[median2-1]){
                        return (double)(nums2[median2]+nums2[median2-1])/2;
                    }else{
                        return (double)(nums2[median2]+nums1[start1+1])/2;
                    }
                }else{
                    return findMedian(nums1, start1 + 1, end1, nums2, start2, end2-1);
                }
            }
            offset = median1-start1;
            return findMedian(nums1, start1+offset, end1, nums2, start2, end2-offset);
        }else{
            if (median1 == start1) {
                if ((nums1.size() + nums2.size())%2 == 0) {
                    if (nums1[end1] <= nums2[median2+1]) {
                        return (double)(nums1[median1] + nums1[start1+1])/2;
                    }else if ((nums1[end1] > nums2[median2+1] && nums1[start1] <= nums2[median2+1]) || (median2+2 < nums2.size() && nums1[median1] <= nums2[median2+2]) || (median2+2 >= nums2.size() && nums1[start1] >= nums2[median2+1])){
                        return (double)(nums1[median1]+nums2[median2+1])/2;
                    }else {
                        return (double)(nums2[median2+1]+nums2[median2+2])/2;
                    }
                }else{
                    return findMedian(nums1, start1, end1-1, nums2, start2+1, end2);
                }
            }
            offset = end1-median1;
            if ((end1-start1)%2 != 0 && (end2-start2)%2 != 0) {
                offset -= 1;
            }
            return findMedian(nums1, start1, end1-offset, nums2, start2+offset, end2);
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution sl;
    int num1[] = {1,5, 6, 7};
    int num2[] = {2,3,4,8,9,10};
    vector<int> nums1(num1, num1+4);
//    vector<int> nums2(num2, num2+6);
    vector<int> nums2;
    nums2.insert(nums2.begin(), nums1.begin(), nums1.end());
    printf("%d\n",nums2[1]);
    return 0;
}
