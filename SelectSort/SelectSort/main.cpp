//
//  main.cpp
//  SelectSort
//
//  Created by Alps on 15/4/2.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

void SelectSort(int *arr, int length){
    int temp = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/////////////////////////////////////////////
typedef struct node{
    int val;
    node *next;
    node(int v): val(v), next(NULL){}
}*list;

list SelectSort_t(list header){
    if (header == NULL && header->next == NULL) {
        return NULL;
    }
    list swap;
    list curtemp = header;
    list temp = curtemp->next;
    
    while (curtemp && curtemp->next && curtemp->next->next) {
        while (temp && temp->next) {
            if (temp->next->val < curtemp->next->val) {
//                if (curtemp->next == temp) {
//                    curtemp->next = temp->next;
//                    temp->next = temp->next->next;
//                    curtemp->next->next = temp;
//                    continue;
//                }
                swap = temp->next;
                temp->next = swap->next;
                swap->next = curtemp->next;
                curtemp->next = swap;
                continue;
            }
            temp = temp->next;
        }
        curtemp = curtemp->next;
        temp = curtemp->next;
    }
    return header->next;
}





int main(int argc, const char * argv[]) {
    int a[]= {5, 8, 5, 2, 9, 4};
    SelectSort(a, sizeof(a)/sizeof(int));
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    list header = new node(0);
    list temp;
    for (int j = 0; j < 6; j++) {
        temp = (list)malloc(sizeof(struct node));
        scanf("%d", &temp->val);
        temp->next = header->next;
        header->next = temp;
    }
    header = SelectSort_t(header);
    while (header) {
        printf("%d ",header->val);
        header = header->next;
    }
    return 0;
}
