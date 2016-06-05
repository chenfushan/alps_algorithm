#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "AlpsNumber.hpp"

using namespace std;
using namespace AlpsNumber;

#ifndef ll
#define ll long long
#endif

ll rand_Number(ll e){
    return rand()%e+1;;
}

ll mult_mod(ll a,ll b,ll c){
    a %= c;
    b %= c;
    ll res = 0;
    while(b){
        if(b & 1){
            res += a;
            res %= c;
        }
        a <<= 1;
        if(a >= c)
            a %= c;
        b >>= 1;
    }
    return res;
}

ll getRemainder(ll a,ll u, ll num){
    ll cur = 1;
    ll nxt = a;
    while (u) {
        if ((u&1) > 0) {
            cur = mult_mod(cur, nxt, num);
        }
        nxt = mult_mod(nxt, nxt, num);
        u = u>>1;
    }
    return cur%num;
}


bool checkPrime(ll num){
    if (num == 2) {
        return true;
    }
    if (num < 2 || num % 2 == 0) {
        return false;
    }
    ll u = num-1;
    int S = 20;
    while (u % 2 == 0) {
        u /= 2;
    }
    for (int i = 0; i < S; i++) {
        ll a = rand_Number(num-1);
        ll x = getRemainder(a, u, num);
        ll y = x;
        ll tu = u;
        while (tu < num) {
            y = mult_mod(x, x, num);;
            if (y == 1 && x != 1 && x != num-1) {
                return false;
            }
            x = y;
            tu *= 2;
        }
        if (x != 1) {
            return false;
        }
    }
    return true;
}

int main(){
    ll m,n;
    srand((unsigned)time(NULL));
    scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &n);
        
        if (checkPrime(n)) {
            cout<<"Yes"<<endl;
            continue;
        }else{
            cout<<"No"<<endl;
            continue;
        }
    }
    
    return 0;
}