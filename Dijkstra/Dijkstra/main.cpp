//
//  main.cpp
//  Dijkstra
//
//  Created by Alps on 15/3/4.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>

#ifndef NumVertex
#define NumVertex 4
#endif

#ifndef Infinity
#define Infinity 10000
#endif

using namespace std;

typedef int  Vertex;


struct LinkList{
    int val;
    int length;
    LinkList * next;
    LinkList(int v): val(v), next(NULL) {}
};

typedef LinkList* List;

struct TableEntry{
    List Header;
    bool Know;
    int Dist;
    Vertex Path;
};

typedef struct TableEntry Table[NumVertex+1];

void InitTable(Vertex Start, Table T){
    List temp;
    int OutDegree;
    for (int i = 1; i <= NumVertex; i++) {
        T[i].Know = false;
        T[i].Dist = Infinity;
        T[i].Path = -1;
        T[i].Header = NULL;
        scanf("%d",&OutDegree);
        for (int j = 0; j < OutDegree; j++) {
            temp = (List)malloc(sizeof(struct LinkList));
            scanf("%d %d",&(temp->val), &(temp->length));
            temp->next = T[i].Header;
            T[i].Header = temp;
        }
    }
    
    T[Start].Dist = 0;
}

void PrintPath (Vertex V,Table T){
    if (T[V].Path != -1) {
        PrintPath(T[V].Path, T);
        printf(" to ");
    }
    printf("%d", V);
}

Vertex SmallDistUnknow(Table T){
    int MinDist = Infinity + 1, V = 0;
    for (int i = 1; i <= NumVertex; i++) {
        if (!T[i].Know && T[i].Dist <= MinDist) {
            MinDist = T[i].Dist;
            V = i;
        }
    }
    return V;
}

void Dijkstra(Table T){
    List temp;
    Vertex V;
    while (1) {
        V = SmallDistUnknow(T);
        if (V == 0) {
            break;
        }
        T[V].Know = true;
        temp = T[V].Header;
        while (temp != NULL) {
            if (!T[temp->val].Know) {
                if (T[V].Dist + temp->length < T[temp->val].Dist) {
                    T[temp->val].Dist = T[V].Dist + temp->length;
                    T[temp->val].Path = V;
                }
            }
            temp = temp->next;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    Table T;
    
    InitTable(1, T);
    
    Dijkstra(T);
    
    PrintPath(2, T);
    
//    std::cout << "Hello, World!\n";
    return 0;
}
