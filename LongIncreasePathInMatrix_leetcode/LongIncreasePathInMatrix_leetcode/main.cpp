//
//  main.cpp
//  LongIncreasePathInMatrix_leetcode
//
//  Created by Alps on 16/3/8.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        if(rows == 0){
            return 0;
        }
        int  longestPath = 0;
        int cols = (int)matrix[0].size();
        
        int *count[rows];
        for(int i = 0; i < rows; i++){
            count[i] = (int *)malloc(sizeof(int) * cols);
            for(int j = 0; j < cols; j++){
                count[i][j] = -1;
            }
        }
        
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(count[i][j] == -1){
                    this->findLongestPath(matrix, count, rows, cols , i, j);
                }
                longestPath = max(longestPath, count[i][j]);
            }
        }
        return longestPath;
    }
    
    void findLongestPath(vector<vector<int>> matrix, int **count, int &rows, int &cols, int m, int n){
        if(count[m][n] != -1){
            return;
        }
        if(n < cols-1 && matrix[m][n+1] > matrix[m][n]){
            findLongestPath(matrix, count, rows, cols, m, n+1);
            count[m][n] = max(count[m][n], count[m][n+1] + 1);
        }
        if(m < rows-1 &&matrix[m+1][n] > matrix[m][n]){
            findLongestPath(matrix, count, rows, cols, m+1, n);
            count[m][n] = max(count[m][n], count[m+1][n] + 1);
        }
        if(n > 0 && matrix[m][n-1] > matrix[m][n]){
            count[m][n] = max(count[m][n], count[m][n-1] + 1);
        }
        if(m > 0 &&matrix[m-1][n] > matrix[m][n]){
            count[m][n] = max(count[m][n], count[m-1][n] + 1);
        }
        if(count[m][n] == -1){
            count[m][n] = 1;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix;
    vector<int> m1;
    m1.push_back(9);
    m1.push_back(9);
    m1.push_back(4);
    matrix.push_back(m1);
    vector<int> m2;
    m2.push_back(6);
    m2.push_back(6);
    m2.push_back(8);
    matrix.push_back(m2);
    vector<int> m3;
    m3.push_back(2);
    m3.push_back(1);
    m3.push_back(1);
    matrix.push_back(m3);
    Solution sl;
    cout<<sl.longestIncreasingPath(matrix)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
