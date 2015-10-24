//
//  main.cpp
//  LCS
//
//  最长公共子序列(LCS)
//
//  Created by Alps on 15/8/23.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

#ifndef MAX_LENGTH
#define MAX_LENGTH 15
#endif

int MaxNum(int firstNum, int secondNum){
    return firstNum > secondNum ? firstNum : secondNum;
}

struct matrix{
    int num;
    int direct;
};

typedef matrix Matrix;

int LCS(char *strA, char *strB, int lengthA, int lengthB, Matrix *resultMatrix[]){
    if (lengthA == 0 || lengthB == 0) {
        return 0;
    }
    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            resultMatrix[i][j].num = 0; //设置所有默认的最长为0
            resultMatrix[i][j].direct = 1; //所有默认方向变成上 0斜上，1上，-1左
        }
    }
    
    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            if (strA[i] == strB[j]) {
                resultMatrix[i+1][j+1].num = resultMatrix[i][j].num + 1;
                resultMatrix[i+1][j+1].direct = 0;
            }else{
                resultMatrix[i+1][j+1].num = MaxNum(resultMatrix[i+1][j].num, resultMatrix[i][j+1].num);
                resultMatrix[i+1][j+1].direct = resultMatrix[i+1][j].num > resultMatrix[i][j+1].num ? 1 : -1;
            }
        }
    }
    return resultMatrix[lengthA][lengthB].num;
}

int main(int argc, const char * argv[]) {
    char *strA = (char*)malloc(sizeof(char) * MAX_LENGTH);
    char *strB = (char*)malloc(sizeof(char) * MAX_LENGTH);
    scanf("%s",strA);
    scanf("%s",strB);
    int lengthA = (int)strlen(strA);
    int lengthB = (int)strlen(strB);
    Matrix *resultMatrix[lengthA+1];
    for (int i = 0; i <= lengthA; i++) {
        resultMatrix[i] = (Matrix*)malloc(sizeof(struct matrix)* (lengthB+1));
    }
    
    int max = LCS(strA, strB, lengthA, lengthB, resultMatrix);
    printf("%d\n",max);
    std::cout << "Hello, World!\n";
    return 0;
}
