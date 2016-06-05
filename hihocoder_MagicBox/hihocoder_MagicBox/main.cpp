//
//  main.cpp
//  hihocoder_MagicBox
//
//  Created by Alps on 16/1/11.
//  Copyright © 2016年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <stack>

using namespace std;

void SortCount(int& A, int& B, int& C);
void SwitchTwoNumber(int & A, int & B);
bool judgeBall(int CountA, int CountB, int CountC, int CurCr, int CurCy, int CurCb);

int main(int argc, char const *argv[])
{
    int CountA = 0, CountB = 0, CountC = 0;
    scanf("%d %d %d", &CountA, &CountB, &CountC);
    getchar();
    SortCount(CountA, CountB, CountC);
    int CurCr = 0, CurCy = 0, CurCb = 0;
    int MaxLength = 0, LengthBall = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if(c == 'R'){
            CurCr += 1;
        }
        if(c == 'Y'){
            CurCy += 1;
        }
        if(c == 'B'){
            CurCb += 1;
        }
        if(c == '\n'){
            break;
        }
        LengthBall += 1;
        MaxLength = MaxLength > LengthBall ? MaxLength : LengthBall;
        if(judgeBall(CountA, CountB, CountC, CurCr, CurCy, CurCb)){
            LengthBall = 0;
            CurCr = 0;
            CurCy = 0;
            CurCb = 0;
        }
    }
    printf("%d\n", MaxLength);
    return 0;
}

void SortCount(int& A, int& B, int& C){
    if(A >= B){
        if(A >= C){
            if(B >= C){
                return;
            }else{
                SwitchTwoNumber(B, C);
            }
        }else{
            SwitchTwoNumber(A, C);
            SwitchTwoNumber(B, C);
        }
    }else{
        if(B >= C){
            if(A >= C){
                SwitchTwoNumber(A, B);
            }else{
                SwitchTwoNumber(A, B);
                SwitchTwoNumber(B, C);
            }
        }else{
            SwitchTwoNumber(A, C);
        }
    }
}

void SwitchTwoNumber(int & A, int & B){
    B = B+A;
    A = B-A;
    B = B-A;
}

bool judgeBall(int CountA, int CountB, int CountC, int CurCr, int CurCy, int CurCb){
    int tempCr = CurCr, tempCy = CurCy, tempCb = CurCb;
    SortCount(tempCr, tempCy, tempCb);
    if((tempCr - tempCb) == CountA){
        if((tempCr - tempCy) == CountB && (tempCy - tempCb) == CountC){
            return true;
        }else{
            if((tempCr - tempCy) == CountC && (tempCy - tempCb) == CountB){
                return true;
            }else{
                return false;
            }
        }
    }else{
        return false;
    }
}