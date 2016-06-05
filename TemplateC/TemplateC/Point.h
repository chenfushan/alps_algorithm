//
//  Point.h
//  TemplateC
//
//  Created by Alps on 15/12/29.
//  Copyright © 2015年 chen. All rights reserved.
//

#include <iostream>
#include <assert.h>
using namespace std;

#ifndef Point_h
#define Point_h

template < class type, int dim >
class Point{
public:
    Point();
    Point(type coords[dim]){
        for (int index = 0; index < dim; index++) {
            _coords[index] = coords[index];
        }
    }
    
    type& operator[] (int index){
        assert(index < dim && index >= 0);
        return _coords[index];
    }
    
    type operator[] ( int index ) const{
        assert(index < dim && index >= 0);
        return _coords[index];
    }
    
private:
    type _coords[dim];
};

template < class type, int dim >
inline
ostream&
operator<<( ostream &os, const Point < type, dim > &pt){
    os << "( ";
    for (int ix = 0; ix < dim-1; ix++) {
        os << pt[ ix ] << ", ";
    }
    os << pt[ dim -1 ];
    os << " )";
}


template < class type >
class Point3d
{
public:
    Point3d( type x = 0.0, type y = 0.0, type z = 0.0)
    : _x(x), _y(y), _z(z) {}
    
    type x(){
        return _x;
    }
    
    void x( type xval ){
        _x = xval;
    }
    
private:
    type _x;
    type _y;
    type _z;
};


#endif /* Point_h */
