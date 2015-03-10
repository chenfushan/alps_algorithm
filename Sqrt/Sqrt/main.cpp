//
//  main.cpp
//  Sqrt
//
//  Created by Alps on 14/12/11.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution{
public:
    int sqrt(int x){
        if (x <= 0) {
            return 0;
        }
        int length = 0;
        int temp = x/2;
        while (temp) {
            length++;
            temp/=2;
        }
        int i = pow(2,length/2);
        printf("%d\n",i);
        for (; i <= x && i <= 46340; i++) {
            temp = i * i;
            if (temp == x) {
                return i;
            }
            if (temp > x) {
                return i-1;
            }
        }
        return 46340;
    }
};

int main(int argc, const char * argv[]) {
    Solution sl;
    printf("%d\n",sl.sqrt(2147395599));
}
