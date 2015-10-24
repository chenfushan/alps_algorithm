//
//  main.cpp
//  SummaryRange
//
//  Created by Alps on 15/7/1.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int length = nums.size();
        vector<string> res;
        if(length == 0){
            return res;
        }
        string temp = "";
        stringstream ss;
        int begin = nums[0], count = 0;
        for(int i = 1; i < length; i++){
            // if(count == 0){
            //     begin = nums[i];
            //     count++;
            //     continue;
            // }
            if(nums[i] - begin - count == 1){
                count++;
            }else{
                if(count != 0){
                    ss<<begin;
                    temp= ss.str();
                    temp += "->";
                    ss.str("");
                    ss<<(begin+count);
                    temp += ss.str();
                    ss.str("");
                    res.push_back(temp);
                }else{
                    ss<<begin;
                    res.push_back(ss.str());
                    ss.str("");
                }
                count = 0;
                begin = nums[i];
            }
        }
        if(count != 0){
            ss.str("");
            ss<<begin;
            temp= ss.str();
            temp += "->";
            ss.str("");
            ss<<(begin+count);
            temp += ss.str();
            ss.str("");
            res.push_back(temp);
        }else{
            ss.str("");
            ss<<begin;
            res.push_back(ss.str());
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    Solution sl;
    vector<string> res = sl.summaryRanges(a);
    printf("%s",res[0].c_str());
    std::cout << "Hello, World!\n";
    return 0;
}
