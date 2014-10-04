//
//  main.cpp
//  Sum_HDU
//
//  Created by Alps on 14-10-4.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a,i;
    int answer;
    while (scanf("%d",&a) != EOF) {
        answer = 0;
        for (i = 1 ; i <= a; i++) {
            answer += i;
        }
        printf("%d\n\n",answer);
        
    }
    return 0;
}
