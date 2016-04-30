//
//  main.cpp
//  SegmentTree
//
//  Created by Alps on 16/5/1.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 *  Segement Tree Node struct
 *  countValue : count for value in segment
 *  countSegement : count for segement(lower, upper)
 *  maxValue: max value for the node
 *  minValue: min value for the node
 */
struct TreeNode{
    int countValue;
    int countSegment;
    int maxValue, minValue;
    TreeNode * left;
    TreeNode * right;
};

/**
 *  Initial the Segment Tree, keep the num in vector
 *
 *  @param nums  the segmetn number
 *  @param left  left loc in vector<int>nums
 *  @param right right loc in vecotr<int>nums
 *
 *  @return SegmentTree node
 */
TreeNode * InitSegmentTree(vector<int> nums, int left, int right){
    if(left > right) return NULL;
    
    TreeNode * root = new TreeNode();
    root->countValue = 0;
    root->countSegment = 0;
    root->maxValue = nums[right];
    root->minValue = nums[left];
    root->left = NULL;
    root->right = NULL;
    if (left == right) {
        return root;
    }
    
    int mid = (left+right)/2;
    root->left = InitSegmentTree(nums, left, mid);
    root->right = InitSegmentTree(nums, mid+1, right);
    
    return root;
}

/**
 *  add a value into the segment tree
 *
 *  @param value add value
 *  @param root  segment tree root node
 *
 *  @return add success : true, fail : false;
 */
bool add(int value, TreeNode * root){
    if (root == NULL) {
        return false;
    }
    if (value < root->minValue || value > root->maxValue) {
        return false;
    }
    root->countValue++;
    if (root->left && value <= root->left->maxValue) {
        return  add(value, root->left);
    }else if(root->right && value >= root->right->minValue){
        return add(value, root->right);
    }
    return true;
}

/**
 *  get the number loc in segment tree
 *
 *  @param lower segment lower number for search
 *  @param upper segment upper number for search
 *  @param root  segment tree root node
 *
 *  @return the count of number in segment tree between lower and upper
 */
int getCount(int lower, int upper, TreeNode * root){
    if (root == NULL) {
        return 0;
    }
    if (lower <= root->minValue && upper >= root->maxValue) {
        return root->countValue;
    }
    if (lower > root->maxValue || upper < root->minValue) {
        return 0;
    }
    int leftCount = root->left ? getCount(lower, upper, root->left) : 0 ;
    int rightCount = root->right ? getCount(lower, upper, root->right) : 0;
    
    return leftCount + rightCount;
}

/**
 *  add a segment to segment tree
 *
 *  @param lower segment lower number for add
 *  @param upper segment upper number for add
 *  @param root  setment tree root node
 *
 *  @return add if success true:false;
 */
bool addSegment(int lower, int upper, TreeNode *root){
    if (root == NULL) {
        return false;
    }
    if (lower < root->minValue || upper > root->maxValue) {
        return false;
    }
    if (lower == root->minValue && upper == root->maxValue) {
        root->countSegment++;
        return true;
    }
    if (!root->left) {
        return false;
    }
    int mid = root->left->maxValue;
    if (upper <= mid) {
        return addSegment(lower, upper, root->left);
    }
    if (!root->right) {
        return false;
    }
    if (lower > mid) {
        return addSegment(lower, upper, root->right);
    }
    addSegment(lower, mid, root->left);
    addSegment(mid+1, upper, root->right);
    return true;
}

/**
 *  get the count of segment contain the value
 *
 *  @param value value for search
 *  @param root  segment tree root node
 *
 *  @return return the count of segment
 */
int getSegmentCount(int value, TreeNode * root){
    if (value < root->minValue || value > root->maxValue) {
        return 0;
    }
    int count = root->countSegment;
    if (root->maxValue == root->minValue) {
        return count;
    }
    int mid = root->left->maxValue;
    if (value <= mid) {
        count += getSegmentCount(value, root->left);
    }
    if (value > mid) {
        count += getSegmentCount(value, root->right);
    }
    return count;
}


int main(int argc, const char * argv[]) {
    vector<int> temp = {0,1,2,3,4,5,6,7};
    TreeNode * root = InitSegmentTree(temp, 0, (int)temp.size()-1);
    add(4, root);
    add(6, root);
    cout<<getCount(4, 6, root)<<endl;
    addSegment(2, 5, root);
    addSegment(4, 6, root);
    cout<<getSegmentCount(3, root)<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
