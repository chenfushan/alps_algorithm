//
//  main.cpp
//  testduotai
//
//  Created by Alps on 14-7-22.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"A"<<endl;
    }
    void foo()
    {
        cout<<"A::function fooa"<<endl;
    }
    virtual void fuu()
    {
        cout<<"A::function fuua"<<endl;
    }
};
class B:public A
{
public:
    B(int i)
    {
        cout<<"B"<<endl;
    }
    void foo()
    {
        cout<<"B::function foob"<<endl;
    }
    void fuu()
    {
        cout<<"B::function fuub"<<endl;
    }
};
int main()
{
    A *a = new A();
    A *b = new B(1);
    
    a->foo();
    a->fuu();
    b->foo();
    b->fuu();
    return 0;
}
