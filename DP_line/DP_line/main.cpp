//
//  main.cpp
//  DP_line
//
//  Created by Alps on 15/4/26.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

#define NUM 5

int main(){
    int first[NUM];//到装备站1,i的最短路径长度
    int second[NUM];//到装配站2,i的最短路径长度
    int linef[NUM]; //从1进入的路径
    int lines[NUM]; //从2进入的路径
    int a[NUM]; //在装配站1,i 所需要呆的时间
    int b[NUM]; //再装配站2,i 所需要呆的时间
    int m[NUM]; //从装配站1,i-1 到装配站2,i的时间
    int n[NUM]; //从装配站2,i-1 到装配站1,i的时间
    int line[NUM]; //当前最短路经所经过的装配站
    int f[NUM]; //当前最短路径长度
    int ea,eb,xa,xb; // ea为进入装配站1时间，eb为进入2的时间，xa为出装配站1的时间，xb为出装配站2的
    
    scanf("%d %d %d %d",&ea,&eb,&xa,&xb);
    for(int i=0;i<NUM;++i)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    first[0] = ea + a[0];
    second[0] = eb + b[0];
    for(int i=0;i<NUM-1;++i)
    {
        scanf("%d %d", &m[i], &n[i]);
    }
    for(int i=1;i<NUM;++i)
    {
        if(first[i-1] + a[i] < second[i-1] + m[i-1] + a[i])
        {
            first[i] = first[i-1] + a[i];
            linef[i] = 1;
        }else{
            first[i] = second[i-1] + m[i-1] + a[i];
            linef[i] = 2;
        }
        if(second[i-1] + b[i] < first[i-1] + n[i-1] + b[i])
        {
            second[i] = second[i-1] + b[i];
            lines[i] = 2;
        }else
        {
            second[i] = first[i-1] + n[i-1] + b[i-1];
            lines[i] = 1;
        }
    }
    for(int i=0;i<NUM;++i)
    {
        if(first[i] + xa < second[i] + xb)
        {
            f[i] = first[i] + xa;
            line[i] = 1;
        }else{
            f[i] = second[i] + xb;
            line[i] = 2;
        }
    }
    
    for(int i=0;i<NUM;++i)
    {
        printf("station %d\n",line[i]);
    }
    printf("Distince is %d\n",f[NUM-1]);
    
    return 0;
}


