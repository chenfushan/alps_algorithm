//
//  main.cpp
//  DP_01backpack
//
//  Created by Alps on 15/4/28.
//  Copyright (c) 2015年 chen. All rights reserved.
//
// 代码中直接定义了石头的数量和背包的空间，其实可以不用提前定义。
// 这里为了方便，而且在C++ 11中可以动态规定数组大小。

#include <iostream>
using namespace std;

#ifndef STONE_NUM
#define STONE_NUM 5 //定义石头数量
#endif

#ifndef BACKPACK_SPACE
#define BACKPACK_SPACE 10
#endif

int main(int argc, const char * argv[]) {
//    int stoneSpace, stoneValue;
    int value[BACKPACK_SPACE+1] = {0};
//    for (int i = 0; i < STONE_NUM; i++) {
//        scanf("%d %d", &stoneSpace, &stoneValue);
//        for (int j = BACKPACK_SPACE; j > 0; j--) {
//            if (j >= stoneSpace && value[j] < (value[j-stoneSpace] + stoneValue)) {
//                value[j] = value[j-stoneSpace] + stoneValue;
//            }
//        }
//    }
//    printf("%d\n", value[BACKPACK_SPACE]);
    int stoneSpace[STONE_NUM],stoneValue[STONE_NUM];
    for (int i = 0; i < STONE_NUM; i++) {
        scanf("%d %d", &stoneSpace[i], &stoneValue[i]);
        for (int j = BACKPACK_SPACE; j > 0; j--) {
            if (j >= stoneSpace[i] && value[j] < value[j-stoneSpace[i]] + stoneValue[i]) {
                value[j] = value[j-stoneSpace[i]] + stoneValue[i];
            }
        }
    }
    for (int i = 0; i <= BACKPACK_SPACE; i++) {
        printf("%d\n", value[i]);
    }

    int backPackSpace = BACKPACK_SPACE;
    while (value[backPackSpace] == value[backPackSpace-1]) {
        backPackSpace--;
    }
    for (int i = STONE_NUM-1; i >= 0; i--) {
        if (value[backPackSpace] == value[backPackSpace-stoneSpace[i]] + stoneValue[i]) {
            printf("%d ", i+1);
            backPackSpace = backPackSpace - stoneSpace[i];
        }
    }
    
    return 0;
}
