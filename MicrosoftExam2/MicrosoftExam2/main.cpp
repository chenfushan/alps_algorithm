//
//  main.cpp
//  MicrosoftExam2
//
//  Created by Alps on 15/4/3.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int start;
    int num;
    vector<int> signal;
};

typedef node* Node;

int main(int argc, const char * argv[]) {
    int numberoftest;
    int numofnode, numofsignal;
    vector<int> startsignal;
    queue<int> Q;
    int tempsignal;
    scanf("%d",&numberoftest);
    for (int i = 0; i < numberoftest; i++) {
        scanf("%d %d",&numofnode, &numofsignal);
        Node N[numofnode];
        int numofstart[numofnode];
        for (int j = 0; j < numofnode; j++) {
            numofstart[j] = 0;
        }
        for (int j = 0; j < numofsignal; j++) {
            scanf("%d",&tempsignal);
            startsignal.push_back(tempsignal);
        }
        for (int j = 0; j < numofnode; j++) {
            N[j] = (Node)malloc(sizeof(struct node));
            scanf("%d %d", &N[j]->start, &N[j]->num);
            for (int h = 0; h < N[j]->num; h++) {
                scanf("%d", &tempsignal);
                N[j]->signal.push_back(tempsignal);
            }
        }
        
        for (int j = 0; j < startsignal.size(); j++) {
            Q.push(startsignal[j]);
        }
        while (!Q.empty()) {
            tempsignal = Q.front();
            Q.pop();
            for (int j = 0; j < numofnode; j++) {
                if (N[j]->start == tempsignal) {
                    numofstart[j] += 1;
                    if (numofstart[j] > 142857) {
                        numofstart[j] = numofstart[j]%142857;
                    }
                    for (int h = 0; h < N[j]->signal.size(); h++) {
                        Q.push(N[j]->signal[h]);
                    }
                }
            }
        }
        
        for (int j = 0; j < numofnode; j++) {
            if (j == numofnode-1) {
                printf("%d\n",numofstart[j]);
                break;
            }
            printf("%d ",numofstart[j]);
        }
        startsignal.clear();
    }
    
    return 0;
}
