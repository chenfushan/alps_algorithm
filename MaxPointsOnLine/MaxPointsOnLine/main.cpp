//
//  main.cpp
//  MaxPointsOnLine
//
//  Created by Alps on 14-9-11.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct Point{
    int x;
    int y;
    Point(): x(0), y(0){}
    Point(int a, int b):x(a),y(b){}
};

class Solution{
public:
    int maxPoints(vector<Point> &points){
        int max = 0;
        float k,b;
        int num = 0;
        bool flag;
        vector<Point>::iterator iterx;
        vector<Point>::iterator itery;
        vector<Point>::iterator iter;
        for (iterx = points.begin(); iterx != points.end(); iterx++) {
            for (itery = iterx; itery != points.end(); itery++) {
                if (itery->x - iterx->x == 0) {
                    flag = false;
                    k = 0;
                    b = iterx->x;
                }else{
                    flag = true;
                    k = (float)(itery->y - iterx->y)/(float)(itery->x - iterx->x);
                    b = (float)((float)iterx->y - (float)(iterx->x)*k);
                }
                
                for (iter = points.begin(); iter != points.end(); iter++) {
                    if (Judge(k, b, iter->x, iter->y, flag)) {
                        num+=1;
                    }
                }
                if (num > max) {
                    max = num;
                }
                num = 0;
            }
        }
        return max;
    }
    
    bool Judge(float k, float b, int x, int y, bool flag){
        if (flag == false) {
            return x == b;
        }
        if (k*(float)x+b-(float)y < 0.0000001 && k*(float)x+b-(float)y > -0.0000001) {
            return true;
        }else{
            return false;
        }
    }
};


int main(int argc, const char * argv[])
{
    vector<Point> points;
    points.push_back(Point(3,10));
    points.push_back(Point(0,2));
    points.push_back(Point(0,2));
    points.push_back(Point(3,10));
//    points.push_back(Point(2,2));
    Solution s;
    int a = s.maxPoints(points);
    printf("%d\n",a);
    return 0;
}

