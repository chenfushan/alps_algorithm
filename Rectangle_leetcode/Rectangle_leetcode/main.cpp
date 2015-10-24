//
//  main.cpp
//  Rectangle_leetcode
//
//  Created by Alps on 15/7/2.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        if(C <= E || D <= F || A >= G || B >= H){
            return area;
        }
        if((C>=E && C <= G)){
            if(B >=F && B <= H){
                if(A <= E){
                    if(D >= H){
                        return area-((H-B)*(C-E));
                    }else{
                        return area-((D-B)*(C-E));
                    }
                }else{
                    if(D >= H){
                        return area-((H-B)*(C-A));
                    }else{
                        return area-(C-A)*(D-B);
                    }
                }
            }else{
                if(A <= E){
                    if(D >= H){
                        return area-((H-F)*(C-E));
                    }else{
                        return area-((D-F)*(C-E));
                    }
                }else{
                    if(D >= H){
                        return area-((H-F)*(C-A));
                    }else{
                        return area-(C-A)*(D-F);
                    }
                }
            }
        }else{
            if(B >=F && B <= H){
                if(A <= E){
                    if(D >= H){
                        return area-((G-E)*(H-B));
                    }else{
                        return area-((G-E)*(D-B));
                    }
                }else{
                    if(D >= H){
                        return area-((G-A)*(H-B));
                    }else{
                        return area-(G-A)*(D-B);
                    }
                }
            }else{
                if(A <= E){
                    if(D >= H){
                        return area-((G-E)*(H-F));
                    }else{
                        return area-((G-E)*(D-F));
                    }
                }else{
                    if(D >= H){
                        return area-((G-A)*(H-F));
                    }else{
                        return area-(G-A)*(D-F);
                    }
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sl;
    printf("%d\n", sl.computeArea(-2, -2, 2, 2, -3, -3, -1, -1));
    std::cout << "Hello, World!\n";
    return 0;
}
