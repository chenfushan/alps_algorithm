//
//  main.cpp
//  C_AA_Test
//
//  Created by Alps on 15/8/17.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class aa{
    
};

class bb{
    
};

class Test{
private:
    int a;
public:
    int testA(vector<aa> a){
        return 1;
    }
    
    int testA(vector<bb> b){
        return 2;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
