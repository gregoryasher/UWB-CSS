//
//  transposelist.h
//  Lab5_Part2
//
//  Created by Gregory Asher on 2/17/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#ifndef TRANSPOSELIST_H
#define TRANSPOSELIST_H
#include <iostream>
#include "dlist.h"

using namespace std;

template<class Object>
class TransposeList : public DList<Object> {
public:
    int find( const Object &obj );
};

#include "transposelist.cpp.h"
#endif