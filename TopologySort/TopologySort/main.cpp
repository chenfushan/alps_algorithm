//
//  main.cpp
//  TopologySort
//
//  Created by Alps on 15/3/3.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int val;
    int length;
    Node* next;
    Node(): val(0), length(0), next(NULL) {}
};

typedef Node* Graph;

int *degree;

Graph CreateG (Graph G){
    int num;
    scanf("%d", &num); // input the number of the vertex
    G = (Graph)malloc(sizeof(struct Node) * (num+1)); //malloc memory for graph
    G[0].length = num; //save the graph vertex number
    degree = (int *)malloc((num+1) * sizeof(int));
    memset(degree, 0, num*sizeof(int));
    for (int i = 1; i <= num; i++) {
        G[i].val = i;
        G[i].next = NULL;
        int outdegree = 0;
        scanf("%d", &outdegree);
        for (int j = 0; j < outdegree; j++) {
            Node* temp = (Node*)malloc(sizeof(struct Node));
            scanf("%d %d",&(temp->val), &(temp->length));
            temp->next = G[i].next;
            G[i].next = temp;
            degree[temp->val] += 1;
        }
    }
    return G;
}

void PrintG (Graph G){
//    int length = sizeof(G)/sizeof(struct Node);
    int length = G[0].length;
    Node * temp;
    for (int i = 1; i <= length; i++) {
        temp = &G[i];
        printf("Node: %d ",temp->val);
        while (temp->next) {
            printf("-> %d(%d)",temp->next->val, temp->next->length);
            temp = temp->next;
        }
        printf("\n");
    }
}

int* TopologySort (Graph G){
    queue<Node> Q;
    int counter = 0;
    int length = G[0].length;
    int *TopNum = (int*)malloc((length+1) * sizeof(int));
    for (int i = 1; i <= length; i++) {
        if (degree[i] == 0) {
            Q.push(G[i]);
        }
    }
    while (!Q.empty()) {
        Node V = Q.front();
        TopNum[V.val] = ++counter;
        Node * temp = &V;
        while (temp->next) {
            temp = temp->next;
            degree[temp->val] -= 1;
            if (degree[temp->val] == 0) {
                Q.push(G[temp->val]);
            }
        }
        Q.pop();
    }
    
    if (length != counter) {
        return NULL;
    }
    
    return TopNum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Graph G;
    G = CreateG(G);
    
    PrintG(G);
    
    int *TopNum = TopologySort(G);
    for (int i = 1;TopNum != NULL && i <= G[0].length; i++) {
        printf("%d ",TopNum[i]);
    }
//    std::cout << "Hello, World!\n";
    return 0;
}
