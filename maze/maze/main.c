//
//  main.c
//  maze
//
//  Created by Alps on 14-10-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <stdio.h>
#include "maze.h"

Pos nextpos(Pos P, int direction){ //返回下一个试探的位置
    switch (direction) {
        case 1:
            P.col+=1;//东，列+1
            return P;
            break;
        case 2:
            P.row+=1;//南
            return P;
            break;
        case 3:
            P.col-=1;//西
            return P;
            break;
        case 4:
            P.row-=1;//北
            return P;
            break;
        default:
            break;
    }
    return P;
}

int findPath(int maze[10][10],Stack *S, Pos start, Pos end){
    int step = 1;
    Pos curPositoin = start;
    do{
        if (maze[curPositoin.row][curPositoin.col] == 0) {//假如现在的位置是0，证明可以通过
            maze[curPositoin.row][curPositoin.col] = 2;//把当前位置的值变为2，证明走过了。
            Position e = {step, curPositoin, 1};//创建当前步，记录了第几步，这步所处的坐标，还有准备要走的下一个方向
            Push(S, e);//把当前步压到栈中
            if (curPositoin.col == end.col && curPositoin.row == end.row) {//假如和终点坐标相等，返回
                return 0;
            }
            curPositoin.col+=1; //下一个位置是东面，行不变，列+1
            step += 1;//步数+1
        }else{
            if (!IsEmpty(S)) {//假如栈不为空，说明没有退回到起点
                Position e = Pop(S);//弹出栈顶元素
                step-=1;
                while (e.direction == 4 && !IsEmpty(S)) {//假如4个方向都已经尝试过了，那么就继续回退一步
                    e = Pop(S);
                    step-=1;
                }
                if (e.direction < 4) {//假如还有方向没有尝试过
                    e.direction++;//尝试下一个方向
                    Push(S, e);//把当前位置压入栈
                    step+=1;
                    curPositoin = nextpos(e.P, e.direction);//找到下一个方向的位置
                }
            }
        }
    }while(!IsEmpty(S));//栈不为空，也就没有退回到起点
    
    return 0;
}



int main(int argc, const char * argv[]) {
    int maze[10][10] = {{1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},{1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},{1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}};
    int i = 0,j = 0;
    for (i = 0;i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }//打印迷宫
    Stack S;
    InitStack(&S);//建立空栈
    Pos start = {1,1};//起点
    Pos end = {8,8};//终点
    findPath(maze, &S, start, end);
    while (!IsEmpty(&S)) {//打印步骤
        Position foot = Pop(&S);
        printf("%d %d->",foot.P.row,foot.P.col);
    }
    return 0;
}
