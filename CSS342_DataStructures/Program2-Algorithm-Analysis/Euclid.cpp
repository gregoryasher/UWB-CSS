//
//  Euclid.cpp
//  Program2
//
//  Created by Gregory Asher on 1/29/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//
#ifndef EUCLID_CPP
#define EUCLID_CPP
#include "Euclid.h"

//Constructor
Euclid::Euclid(int a, int b){
    partA = a;
    partB = b;
    this->modOperationsCount = 0; //set default value
    this->greatestCommonDenom = 1; //set default value
    this->gcd(); //replaces default values with true values
}
void Euclid::gcd(){
    int r = 0, a = this->partA, b = this->partB; //delaration of placeholder r, copy values of partA and partB to temp values;
    while(b > 1){ //while loop to run where b is greater than zero, ie; until a gcd is found.
        r = a % b;
        a = b;
        b = r;
        this->modOperationsCount++;
    }
    this->greatestCommonDenom = r;
}
int Euclid::getGCDValue() const{
    return this->greatestCommonDenom;
}
int Euclid::getOperationCount() const{
    return this->modOperationsCount;
}
int Euclid::getPartA() const{
    return this->partA;
}
int Euclid::getPartB() const{
    return this->partB;
}
#endif
