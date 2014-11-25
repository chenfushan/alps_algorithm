//
//  main.cpp
//  HuffmanCode
//
//  Created by Alps on 14/11/22.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct HTNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode, *HuffmanTree;
typedef char** HuffmanCode;

void Select(HuffmanTree &HT, int i, int child1, int child2);

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
    //
    int m,i;
    int child1,child2;
    HuffmanTree p;
    if (n <= 1) {
        return;
    }
    m = n*2-1;//整棵树的节点数
    HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode));//申请足够空间
    for (i = 1; i <= n; i++,w++) {
        HT[i] = {*w, 0, 0, 0};
    }
    for (; i <= m; i++) {
        HT[i] = {0, 0, 0, 0};
    }
    for (i = n+1; i <= m; i++) {
        Select(HT,i-1,child1,child2);
        HT[child1].parent = i;
        HT[child2].parent = i;
        HT[i].lchild = child1;
        HT[i].rchild = child2;
    }
    
    HC = (char**)malloc(n*sizeof(char *));
    
    char *cd = (char*)malloc(n*sizeof(char));
    memset(cd, '\0', n*sizeof(char));
    for (<#initialization#>; <#condition#>; <#increment#>) {
        <#statements#>
    }
}






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
