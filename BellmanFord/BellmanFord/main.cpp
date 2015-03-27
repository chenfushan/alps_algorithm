//
//  main.cpp
//  BellmanFord
//
//  Created by Alps on 15/3/26.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef NumVertex
#define NumVertex 4
#endif

#ifndef Infinity
#define Infinity 1000
#endif

typedef int Vertex;

struct LinkList{
    int val;
    int weight;
    LinkList * next;
    LinkList(int v, int w): val(v), weight(w), next(NULL){}
};

typedef LinkList* VList;

struct TableEntry{
    VList Header;
    Vertex Dist;
    Vertex Path;
};

typedef TableEntry Table[NumVertex+1];

void InitTable(Vertex start, Table T){
    
    int OutDegree = 0;
    VList temp = NULL;
    
    for (int i = 1; i <=NumVertex; i++) {
        T[i].Header = NULL; // init the vertex
        T[i].Dist = Infinity;
        T[i].Path = -1;
        
        scanf("%d",&OutDegree);
        
        for (int j = 0; j < OutDegree; j++) { // init the link vertex
            temp = (VList)malloc(sizeof(struct LinkList));
            scanf("%d %d", &temp->val, &temp->weight);
            temp->next = T[i].Header;
            T[i].Header = temp;
        }
        
    }
    
    T[start].Dist = 0;
}

void PrintPath(Vertex V, Table T){
    if (T[V].Path != -1) {
        PrintPath(T[V].Path, T);
        printf(" to ");
    }
    printf("%d", V);
}

bool BellFord(Vertex start, Table T){
    bool Update = false;
    VList temp;
    
    for (int i = 1; i <= NumVertex; i++) { //cycle the num of vertex
        Update = false;
        
        for (int j = 1; j <= NumVertex; j++) { // traversal all the vertex
            if (T[j].Dist != Infinity) { // if the current vertex distance is not Inf
                temp = T[j].Header;
                while (temp != NULL) { // if it have traversaled the link vertex
                    if (T[j].Dist + temp->weight < T[temp->val].Dist) { //if need to relax
                        T[temp->val].Dist = T[j].Dist + temp->weight; //relax operation
                        T[temp->val].Path = j; // mark the path
                        Update = true; // mark the vertex update is true
                    }
                    temp = temp->next; // find the next node
                }
            }
        }
    }
    
    if (Update == true) {
        return false; // if the Graph have a negative cycle
    }else{
        return true; // no negative cycle
    }
}

int main(int argc, const char * argv[]) {
    Table T;
    
    InitTable(1, T);
    
    if (!BellFord(1, T)) {
        printf("There is a cycle!\n");
        return 0;
    }
    
    PrintPath(3, T);
    
    return 0;
}
