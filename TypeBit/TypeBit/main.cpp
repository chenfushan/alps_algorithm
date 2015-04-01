//
//  main.cpp
//  TypeBit
//
//  Created by Alps on 15/4/1.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    short int a = 0;
    int b = 0;
    unsigned int c = 0;
    long int d = 0;
    long long e = 0;
    char f = 0;
    float g = 0;
    double h = 0;
    
    printf("short int is: %lu byte\n",sizeof(a));
    printf("int is : %lu byte\n",sizeof(b));
    printf("unsigned int is: %lu byte\n",sizeof(c));
    printf("long int is : %lu byte\n",sizeof(d));
    printf("long long is : %lu byte\n",sizeof(e));
    printf("char is : %lu byte\n",sizeof(f));
    printf("float is : %lu byte\n",sizeof(g));
    printf("double is : %lu byte\n",sizeof(h));
    return 0;
}
