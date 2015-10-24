//
//  main.cpp
//  MicrosoftExam3
//
//  Created by Alps on 15/4/3.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct location{
    int x;
    int y;
};

vector<location*> V;

int Min(struct location * l1, struct location * l2){
    if (abs(l1->x - l2->x) < abs(l1->y - l2->y)) {
        return abs(l1->x - l2->x);
    }else{
        return abs(l1->y - l2->y);
    }
}

struct table{
    int *arr;
    bool know;
    int Dist;
};

int smallDist(table T[], int num){
    int minDist = 1000000002, v = -1;
    for (int i = 0; i < num; i++) {
        if (!T[i].know && T[i].Dist <= minDist) {
            minDist = T[i].Dist;
            v = i;
        }
    }
    return v;
}

int main(int argc, const char * argv[]) {
    int numoftest = 0;
    scanf("%d",&numoftest);
    int **A = new int*[numoftest];
    for (int i = 0; i < numoftest; i++) {
        A[i] = new int[numoftest];
    }
    struct location* loc;
    for (int i = 0; i < numoftest; i++) {
        loc = (location*)malloc(sizeof(struct location));
        scanf("%d %d",&loc->x, &loc->y);
        V.push_back(loc);
    }
    
    for (int i = 0; i < numoftest; i++) {
        for (int j = 0; j < numoftest; j++) {
            A[i][j] = Min(V[i], V[j]);
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    typedef table* Ta;
    
    Ta T = new struct table[numoftest];
    for (int i = 0; i < numoftest; i++) {
        T[i].arr = A[i];
        T[i].Dist = 1000000001;
        T[i].know = false;
    }
    T[0].Dist = 0;
    int smallv = 0;
    while (1) {
        smallv = smallDist(T, numoftest);
        if (smallv == -1) {
            break;
        }
        T[smallv].know = true;
        for (int j = 0; j < numoftest; j++) {
            if (!T[j].know) {
                if (T[smallv].Dist + T[smallv].arr[j] < T[j].Dist) {
                    T[j].Dist = T[smallv].Dist + T[smallv].arr[j];
                }
            }
        }
    }
    
    printf("%d\n",T[numoftest-1].Dist);
    
    return 0;
}
