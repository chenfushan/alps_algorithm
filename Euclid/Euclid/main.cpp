//
//  main.cpp
//  Euclid
//
//  Created by Alps on 14-7-24.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

int Eud(int M, int N){
    int tmp;
    while (N > 0) {
        tmp = M % N;
        M = N;
        N = tmp;
    }
    return M;
}

int main(int argc, const char * argv[])
{

    int M, N;
    scanf("%d %d",&M, &N);
    if (M < N) {
        M += N;
        N = M - N;
        M = M - N;
    }
    int Rem = Eud(M, N);
    printf("Rem is %d\n",Rem);
    return 0;
}

