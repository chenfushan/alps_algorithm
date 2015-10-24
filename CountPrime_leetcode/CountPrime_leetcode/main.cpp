//
//  main.cpp
//  CountPrime_leetcode
//
//  Created by Alps on 15/4/29.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        bool isprime = true;
        vector<int> prime;
        prime.push_back(2);
        int count = 0;
        for(int i = 3; i < n; i+=2){
            for(int j = 0; j < prime.size(); j++){
                count++;
                if(prime[j] > sqrt(i)){
                    break;
                }
                if(i % prime[j] == 0){
                    isprime = false;
                    break;
                }
            }
            printf("%d ", count);
            count = 0;
            if(isprime == true){
                prime.push_back(i);
            }else{
                isprime = true;
            }
        }
        
        return (int)prime.size();
    }
};
int main(int argc, const char * argv[]) {
    Solution sl;
    sl.countPrimes(150000);
    std::cout << "Hello, World!\n";
    return 0;
}
