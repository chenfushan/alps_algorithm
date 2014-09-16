//
//  main.cpp
//  PasswordAttacker_googlecodejam
//
//  Created by Alps on 14-9-15.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int T = 0;
    int M,N,i;
    int first,second = 1,third = 1;
    int j,k;
    scanf("%d",&T);
    for (i = 0; i < T; i++) {
        scanf("%d %d",&M,&N);
        for (j = N-M+1; j > 0; j--) {
            third = third * j;
        }
        for (j = N; j >= N-M+1; j--) {
            second = second * j;
        }
        first = M;
        k = first * second / third;
        printf("Case #%d: %d\n",i+1,k);
        first = 1;
        second = 1;
        third = 1;
    }
    
    return 0;
}

