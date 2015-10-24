//
//  main.cpp
//  MicrosoftExam
//
//  Created by Alps on 15/4/3.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

bool examBall(int ball[], int a, int b, int c){
    if ((abs(ball[0] - ball[1]) == a) && (abs(ball[0] - ball[2]) == b) && (abs(ball[1] - ball[2]) == c)) {
        return true;
    }
    if ((abs(ball[0] - ball[1]) == a) && (abs(ball[0] - ball[2]) == c) && (abs(ball[1] - ball[2]) == b)) {
        return true;
    }
    if ((abs(ball[0] - ball[1]) == b) && (abs(ball[0] - ball[2]) == a) && (abs(ball[1] - ball[2]) == c)) {
        return true;
    }
    if ((abs(ball[0] - ball[1]) == c) && (abs(ball[0] - ball[2]) == b) && (abs(ball[1] - ball[2]) == a)) {
        return true;
    }
    if ((abs(ball[0] - ball[1]) == b) && (abs(ball[0] - ball[2]) == c) && (abs(ball[1] - ball[2]) == a)) {
        return true;
    }
    if ((abs(ball[0] - ball[1]) == c) && (abs(ball[0] - ball[2]) == a) && (abs(ball[1] - ball[2]) == b)) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int a,b,c;
    int temp = 0;
    int max = 0;
    int ball[3] = {0,0,0};
    scanf("%d %d %d",&a,&b,&c);
    string str;
    cin>>str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'R') {
            ball[0] += 1;
            max += 1;
        }else{
            if (str[i] == 'Y') {
                ball[1] += 1;
                max += 1;
            }else{
                if (str[i] == 'B') {
                    ball[2] += 1;
                    max += 1;
                }
            }
        }
        if (examBall(ball, a, b, c)) {
            ball[0] = 0;
            ball[1] = 0;
            ball[2] = 0;
            temp = max > temp ? max:temp;
            max = 0;
        }
    }
    printf("%d\n",max>temp?max:temp);
    return 0;
}
