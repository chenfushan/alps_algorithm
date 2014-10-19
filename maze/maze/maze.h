//
//  maze.h
//  maze
//
//  Created by Alps on 14-10-17.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#ifndef maze_maze_h
#define maze_maze_h

#define column 10
#define rows 10

typedef struct Pos{
    int col;
    int row;
}Pos;

typedef struct Position{
    int order;
    Pos P;
    int direction;
}Position;

typedef struct Stack{
    Position *top;
    Position *base;
    int stacksize;
}Stack;

void InitStack(Stack *S){
    S->base = (Position *)malloc(column*rows * sizeof(struct Position));
    if (!S->base) {
        return;
    }
    S->top = S->base;
    S->stacksize = column*rows;
}

void Push(Stack *S, Position P){
    if (S->top - S->base >= S->stacksize) {
        S->base = (Position *)realloc(S->base, (S->stacksize + column) * sizeof(struct Position));
        if (!S->base) {
            return;
        }
    }
    *S->top = P;
    S->top++;
}

Position GetTop(Stack *S){
    if (S->top == S->base) {
        exit(0);
    }
    return *(S->top-1);
}

Position Pop(Stack *S){
    if (S->top == S->base) {
        exit(0);
    }
    return *(--(S->top));
}

int StackLength(Stack *S){
    return (int)(S->top-S->base);
}

int IsEmpty(Stack *S){
    if (S->top == S->base) {
        return 1;
    }else{
        return 0;
    }
}




#endif
