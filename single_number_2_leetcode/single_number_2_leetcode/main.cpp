//
//  main.cpp
//  single_number_2_leetcode
//
//  Created by Alps on 15/5/13.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_count[32] = {0};
        int temp = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            temp = nums[i];
            if(temp < 0 && temp != -2147483648){
                one_count[31] ++;
            }
            j = 0;
            while(temp != 0){
                if((temp%2) != 0){
                    one_count[j]++;
                }
                temp = temp/2;
                j++;
            }
        }
        temp = 1;
        int result = 0;
        for(int i = 0; i < 31; i++){
            if(one_count[i]%3 == 1){
                result += temp;
            }
            temp = temp*2;
        }
        if(result == 0 && one_count[31] % 3 == 1){
            result = -2147483648;
        }else{
            if(result != 0 && one_count[31] % 3 == 1){
                result = -result;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sl;
    
    vector<int> v = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,-2147483648,2147483645,-814645,2147483645,-216555};
    cout<< sl.singleNumber(v) <<endl;
    int a = -2147483647;
    cout<< -a <<endl;
    
    
    return 0;
}
