//
//  main.cpp
//  Euclidean
//
//  Created by Alps on 15/3/28.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

int gcd(int a, int b){
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

int gcd_t(int a, int b){
    int temp = a;
    while(a%b != 0){
        a = b;
        b = temp%b;
        temp = a;
    }
    return b;
}

int MinMultiple(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(int argc, const char * argv[]) {
    int a = 14, b = 18;
    int i = 100000;
    double start = (double)clock();
    for (int j = 0; j < i; j++) {
        gcd(a,b);
    }
    double end = (double)clock();
    printf("%f\n",end - start);
    
    start = (double)clock();
    for (int j = 0; j < i; j++) {
        gcd_t(a,b);
    }
    end = (double)clock();
    
    printf("%f\n",end - start);
    return 0;
}
