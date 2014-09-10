//
//  main.cpp
//  ReversePolishNotation
//
//  Created by Alps on 14-9-10.
//  Copyright (c) 2014年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<string>::iterator iter;
        vector<int> temp;
        int number;
        int a,b;
        vector<int>::reverse_iterator riter;
        for (iter = tokens.begin(); iter != tokens.end(); iter++) {
            if (*iter == "+") {
                riter = temp.rbegin();
                a = *riter;
                temp.pop_back();
                riter = temp.rbegin();
                b = *riter;
                temp.pop_back();
                temp.push_back(a+b);
            }else if (*iter == "-"){
                riter = temp.rbegin();
                a = *riter;
                temp.pop_back();
                riter = temp.rbegin();
                b = *riter;
                temp.pop_back();
                temp.push_back(b-a);
            }else if (*iter == "*"){
                riter = temp.rbegin();
                a = *riter;
                temp.pop_back();
                riter = temp.rbegin();
                b = *riter;
                temp.pop_back();
                temp.push_back(a*b);
            }else if (*iter == "/"){
                riter = temp.rbegin();
                a = *riter;
                temp.pop_back();
                riter = temp.rbegin();
                b = *riter;
                temp.pop_back();
                temp.push_back(b/a);
            }else{
                number = atoi(iter->c_str());
                temp.push_back(number);
            }
        }
        riter = temp.rbegin();
        return *riter;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<string> veclist;
    veclist.push_back("123");
    veclist.push_back("23");
    veclist.push_back("*");
    veclist.push_back("2");
    veclist.push_back("/");
//    vector<string>::iterator iter;
//    for (iter = veclist.begin(); iter != veclist.end(); iter++) {
//        
//    }
//    vector<string>::reverse_iterator iter1;
//    iter1 = veclist.rbegin();
//    cout<<*iter1<<endl;
    Solution sl;
    int a = sl.evalRPN(veclist);
    printf("%d\n",a);
    return 0;
}

