//
//  main.cpp
//  TwoSum_leetcode
//
//  Created by Alps on 14-9-16.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//class Solution{
//public:
//    vector<int> twoSum(vector<int> &numbers, int target){
//        vector<int> target_vec;
//        vector<int>::iterator iter1;
//        vector<int>::iterator iter2;
//        int i,j;
//        for (iter1 = numbers.begin(),i = 1; iter1 != numbers.end(); iter1++,i++) {
//            for (iter2 = iter1, j = 2; iter2 != numbers.end();j++) {
//                ++iter2;
//                if (*iter1 + *iter2 > target) {
//                    break;
//                }
//                if (*iter1 + *iter2 == target) {
//                    target_vec.push_back(i);
//                    target_vec.push_back(j);
//                    return target_vec;
//                }
//            }
//        }
//        return target_vec;
//    }
//};
//******************************* this is solution O(N^2) **********************//

class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<int> target_vec;
        vector<int>::iterator iter;
        unordered_map<int, int> hash_map;
        int i = 1;
        int findNum;
        for (iter = numbers.begin(); iter != numbers.end(); iter++, i++) {
            findNum = target - *iter;
            
            if (hash_map.find(findNum) != hash_map.end()) {
                target_vec.push_back(hash_map[findNum]);
                target_vec.push_back(i);
                return target_vec;
            }
            
            hash_map[*iter] = i;
        }
        return target_vec;
    }
};

int main(int argc, const char * argv[])
{
    vector<int> number;
    number.push_back(2);
    number.push_back(7);
    number.push_back(11);
    number.push_back(19);
    Solution sl;
    number = sl.twoSum(number, 9);
    vector<int>::iterator iter;
    for (iter = number.begin(); iter != number.end(); iter++) {
        printf("%d\n",*iter);
    }
    return 0;
}

