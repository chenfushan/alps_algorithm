//
//  main.cpp
//  RMQ_ST
//
//  Created by Alps on 16/5/17.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#ifndef MAXARR
#define MAXARR 100
#endif

using namespace std;

int maxNum[MAXARR][32];
int minNum[MAXARR][32];

void RMQ(int num){
    for (int j = 1; j < 31; j++) {
        for (int i = 0 ; i < num; i++) {
            if (i + (1<<j)-1 < num) {
                maxNum[i][j] = max(maxNum[i][j-1], maxNum[i+(1<<(j-1))][j-1]);
                minNum[i][j] = min(minNum[i][j-1], minNum[i+(1<<(j-1))][j-1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int M,N;
    scanf("%d",&M);
    for (int i = 0; i < M; i++) {
        scanf("%d",&maxNum[i][0]);
        minNum[i][0] = maxNum[i][0];
    }
    RMQ(M);
    scanf("%d",&N);
    int start = 0, end = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d%d",&start,&end);
        int k  = log2(end-start+1);
        cout<<max(maxNum[start][k], maxNum[end-(int)(1<<k)+1][k])<<endl;
        cout<<min(minNum[start][k], minNum[end-(int)(1<<k)+1][k])<<endl;
    }
    return 0;
}
