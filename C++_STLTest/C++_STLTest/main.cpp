//
//  main.cpp
//  C++_STLTest
//
//  Created by Alps on 15/2/17.
//  Copyright (c) 2015年 chen. All rights reserved.
//

//#include <stdio.h>
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

typedef node* LNode;

LNode t(LNode h,int sum)
{
    LNode s = (LNode)malloc(sizeof(struct node));
    s->data = sum;
    s->next = NULL;
    LNode temp = h;
    if (sum < (h->data)) {
        s->next = h;
        h = s;
        return h;
    }
    while (temp->next && sum > temp->next->data) {
        temp = temp->next;
    }
    s->next = temp->next;
    temp->next = s;
    return h;
}

int main()
{
    LNode h=(node*)malloc(sizeof(struct node));
    h->data = 0;
    h->next=NULL;
    LNode temp = h;
    int n = 0;
    while(1)
    {
        scanf("%d",&n);
        if (n == 0) {
            break;
        }
        int sum=0;
        while(n)
        {
            sum+=(n%10);
            n /= 10;
        }
        t(h, sum);
    }
    temp = temp->next;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return 0;
}
