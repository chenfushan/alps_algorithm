//
//  main.cpp
//  VirtualTable
//
//  Created by Alps on 15/4/14.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Base{
public:
    virtual void func(){
        printf("Base\n");
    }
    virtual void hunc(){
        printf("HBase\n");
    }
private:
    virtual void gunc(){
        printf("Base Private\n");
    }
};

class Derive: public Base{
public:
    virtual void func(){
        printf("Derive\n");
    }
};

class DeriveSecond: public Base{
public:
    void func(){
        printf("Second!\n");
    }
};

class DeriveThird: public Base{
};

class DeriveForth: public Base{
public:
    void gunc(){
        printf("Derive Forth\n");
    }
};

int main(int argc, const char * argv[]) {
    Derive d;
    Base *pb = &d;
    pb->func();
    
    DeriveSecond sec;
    pb = &sec;
    pb->func();
    
    DeriveThird thi;
    pb = &thi;
    pb->func();
    
//    pb->gunc();
    typedef void (*Func)(void);
    Func  pFun = Func((long long*)*(long long*)(&thi)+1);
    
    pFun();
    printf("%p\n",((long long *)*(long long*)&d));
    printf("%p\n",&d);
    
    DeriveForth forth;
    pb = &forth;
//    pb->gunc();
    return 0;
}
