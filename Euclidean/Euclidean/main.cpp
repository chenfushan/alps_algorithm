//
//  main.cpp
//  Euclidean
//
//  Created by Alps on 15/3/28.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b){
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

int MinMultiple(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(int argc, const char * argv[]) {
    int a = 14, b = 18;
    printf("%d\n",gcd(a,b));
    return 0;
}
