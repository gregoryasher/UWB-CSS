//
//  Euclid.h
//  Program2
//
//  Created by Gregory Asher on 1/29/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//
#ifndef Euclid_h
#define Euclid_h
#include <sys/time.h>
#include <iostream>

class Euclid {
public:
    Euclid (int a = 5, int b = 8);
    void gcd();
    int getPartA() const;
    int getPartB() const;
    int getGCDValue() const;
    int getOperationCount() const;
private:
    int partA;
    int partB;
    int greatestCommonDenom;
    int modOperationsCount;
};
#endif /* Euclid_h */
