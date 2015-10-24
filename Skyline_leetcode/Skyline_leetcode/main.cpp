//
//  main.cpp
//  Skyline_leetcode
//
//  Created by Alps on 15/5/26.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int maxlength = 0;
        vector<pair<int, int> > result;
        if(buildings.size() == 0){
            return result;
        }
        for(int i = 0; i < buildings.size(); i++){
            maxlength = maxlength > buildings[i][1] ? maxlength : buildings[i][1];
        }
        int final = 0;
        int height[maxlength];
        memset(height, 0, (maxlength) * sizeof(int));
        for(int i = 0; i < buildings.size(); i++){
            for(int j = buildings[i][0]; j <= buildings[i][1]; j++){
                if(j == 2147483647){
                    final = max(final, buildings[i][2]);
                    break;
                }
                height[j] = height[j] > buildings[i][2] ? height[j] : buildings[i][2];
            }
        }
        long curHeight = 0;
        
        for(int i = 0; i < maxlength; i++){
            if(height[i] > curHeight){
                result.push_back(make_pair(i, (int)height[i]));
                curHeight = height[i];
            }else{
                if(height[i] < curHeight){
                    result.push_back(make_pair(i-1, (int)height[i]));
                    curHeight = height[i];
                }
            }
        }
        
        if(final != 0){
            result.push_back(make_pair(2147483647, 0));
        }
        
        return result;
    }
    
    int max(int a, int b){
        return a>b?a:b;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int> > test = {{0, 2147483647, 2147483647}};
    Solution sl;
    vector<pair<int, int> > result = sl.getSkyline(test);
    
    for (int i = 0; i < result.size(); i ++) {
        printf("%d %d\n",result[i].first, result[i].second);
    }
    

    return 0;
}
