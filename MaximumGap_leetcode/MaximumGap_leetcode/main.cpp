//
//  main.cpp
//  MaximumGap_leetcode
//
//  Created by Alps on 14/12/20.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    struct Node{
        int val;
        Node* next;
    };
    
    typedef Node* node;
    
    int maximumGap(vector<int> &num) {
        int max,min;
        int length = (int)num.size();
        if (length < 2) {
            return 0;
        }
        vector<int>::iterator iter;
        min = num[0];
        max = num[0];
        for (iter = num.begin(); iter != num.end(); iter++) {
            if (min > *iter) {
                min = *iter;
                continue;
            }else if(max < *iter){
                max = *iter;
                continue;
            }
        }
        if (max == min) {
            return 0;
        }
        node n[length];
        for (int i = 0; i < length; i++) {
            n[i] = NULL;
        }
        float sub = ((float)(max-min)/(length-1));
        int number;
        node temp;
        for (iter = num.begin(); iter != num.end(); iter++) {
            number = (int)((*iter-min)/sub);
            temp = (node)malloc(sizeof(struct Node));
            temp->val = *iter;
            temp->next= n[number];
//            printf("%d\n",(int)sub);
            n[number] = temp;
        }
        int curmax = -1,nextmin = -1,nextmax = -1,maxSub = 0;
        temp = n[0];
        
        while (temp != NULL) {
            nextmax = nextmax > temp->val ? nextmax: temp->val;
            temp = temp->next;
        }
        
        for (int i = 0; i < length-1; i++) {
            curmax = nextmax;
            while (n[i+1] == NULL) {
                i++;
            }
            temp = n[i+1];
            nextmin = temp->val;
            nextmax = temp->val;
            while (temp != NULL) {
                nextmin = nextmin < temp->val?nextmin:temp->val;
                nextmax = nextmax > temp->val?nextmax:temp->val;
                temp = temp->next;
            }
//            printf("%d %d\n",nextmax,nextmin);
            maxSub = maxSub > (nextmin-curmax)?maxSub:(nextmin-curmax);
        }
        return maxSub;

    }
};

int main(int argc, const char * argv[]) {
    vector<int> num;
    num.push_back(3);
    num.push_back(6);
    num.push_back(9);
    num.push_back(1);
    Solution sl;
    int i = sl.maximumGap(num);
    printf("%d\n",(int)(i/1.5));
    return 0;
}
