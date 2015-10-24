//
//  main.cpp
//  Tecent_exam
//
//  Created by Alps on 15/4/8.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct A{
    unsigned char x;
    unsigned char y;
    int z;
};
#pragma pack(8)
struct B{
    uint8_t a;
    uint32_t b;
    uint16_t c;
};
#pragma pack()
int main(int argc, const char * argv[]) {
    int i = 1;
    int a = 1;
    for (i = 2; ; i++) {
        if (a > (a<<1)) {
            break;
        }
        a = a<<1;
    }
    printf("%d\n",i/8);
    return 0;
}
