//
//  main.cpp
//  BloomFilter
//
//  Created by Alps on 15/3/18.
//  Copyright (c) 2015年 chen. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;


template <class Type> class BloomFilter{
public:
    BloomFilter();
    BloomFilter(int length){
        bitmap.initBitMap(length);
        this->length = length;
    }
    bool Add(const Type &T);
    bool Contains(const Type &T);
    int HasH(const Type &T);
private:
    BitMap bitmap;
    int length;
};
template <class Type> int BloomFilter<Type>::HasH(const Type &T){
    int temp = (int) T;
    return temp%length;
}

template <class Type> bool BloomFilter<Type>::Add(const Type &T){
    int first = HasH(T);
    int second = HasH(first);
    if (bitmap.bitmapSet(first) && bitmap.bitmapSet(second)) {
        return true;
    }else{
        return false;
    }

}

template <class Type> bool BloomFilter<Type>::Contains(const Type &T){
    int first = HasH(T);
    int second = HasH(first);
    if (bitmap.bitmapGet(first) && bitmap.bitmapGet(second)) {
        return true;
    }else{
        return false;
    }
}




int main(int argc, const char * argv[]) {
    
    BloomFilter<int> bloom(10);
    
    bloom.Add(3);
    if (bloom.Contains(3)) {
        printf("true\n");
    }else{
        printf("false\n");
    }
    
    if (bloom.Contains(2)) {
        printf("true\n");
    }else{
        printf("false\n");
    }
    
//    BitMap bit(5);
    
//    printf("%d %d %d\n",bit.bitmapSet(2),bit.bitmapGet(1),bit.bitmapGet(2));
    
    
    return 0;
}
