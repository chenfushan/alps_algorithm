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

#define MAX_INT 4292967295

struct TreeNode{
    int countValue;
    int countSegment;
    long maxValue, minValue;
    TreeNode * left;
    TreeNode * right;
};


TreeNode * InitSegmentTree(vector<long> nums, long left, long right){
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
    
    long mid = (long)(left+right);
    mid /= 2;
    root->left = InitSegmentTree(nums, left, mid);
    root->right = InitSegmentTree(nums, mid+1, right);
    
    return root;
}



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


bool addSegment(long lower, long upper, TreeNode *root){
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
    long mid = root->left->maxValue;
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


int getSegmentCount(int value, TreeNode * root){
    if (value < root->minValue || value > root->maxValue) {
        return 0;
    }
    int count = root->countSegment;
    if (root->maxValue == root->minValue) {
        return count;
    }
    long mid = root->left->maxValue;
    if (value <= mid) {
        count += getSegmentCount(value, root->left);
    }
    if (value > mid) {
        count += getSegmentCount(value, root->right);
    }
    if (count > 1) {
        return 1;
    }else{
        return 0;
    }
}

long transIPtoLong(string str){
    
    return 0;
}


int main(int argc, const char * argv[]) {
    vector<long> IPVector; //防止溢出用Long
    for (long i = 0; i < MAX_INT; i++) {
        IPVector.push_back(i); //把IP简历一个线段树
    }
    TreeNode * root = InitSegmentTree(IPVector, 0, (int)IPVector.size()-1);
    string ip_start, ip_end;
    while (cin>>ip_start>>ip_end) { //这里假设输入的都是IP段,单个IP当做IP段起始和结束时一样的就可以了。
        long ip_s = transIPtoLong(ip_start);
        long ip_e = transIPtoLong(ip_end);
        addSegment(ip_s, ip_e, root); //添加ip段
    }
    string check;
    while (cin>>check) {
        long check_ip = transIPtoLong(check);
        cout<<getSegmentCount(check_ip, root)<<endl; //这里如果输出1 代表存在，输出0代表不存在
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
