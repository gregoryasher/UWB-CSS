//
//  Dragon.h
//  Program3
//
//  Created by Gregory Asher on 2/3/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//
//  ASSUMPTIONS ABOUT THIS ASSIGNMENT ARE AS FOLLOWS:
/*
 I have assumed that the posted driver text is what will be used for compiling my program.
 NOTICE: THE TEXT ON THE ASSIGNMENT PAGE IS ASSUMED TO BE THE DRIVER, NOT A FILE.
 
 ADDITIONALLY: It is assumed that Turtle.cpp and Turtle.h will be provided by the user.
 IE: I am not providing, nor is it stated that I am to provide, the Turtle.cpp OR Turtle.h files.
 
 IN THE TAR FOLDER CONTAINING THIS FILE YOU WILL FIND:
 
 Dragon.cpp
 Dragon.h
 output.pdf
 
 THESE ARE THE REQUESTED AND REQUIRED FILES FOR PROGRAM ASSIGNMENT 3. NO ADDITIONAL FILES WERE REQUESTED OR REQUIRED.
 
 Dragon.cpp and Dragon.h are files that are to accompany Turtle.cpp and Turtle.h such that when run with a
 DragonDriver.cpp (provided by the user) create a Heighway Dragon (AKA: Jurassic Park Dragon, OR Heighway Dragon).
 
 *END ASSUMPTIONS*
 */
//  NOTES:
/*
 This assignment was very similar to Lab 3, so much so that I was able to reuse most of my previously written code.
 Although that being said, I did have to rethink the recursive calls this time around. While very similar, it was quite
 different.
 */

#ifndef Dragon_h
#define Dragon_h

#include "Turtle.h"
#include <iostream>
#include <math.h>

using namespace std;

class Dragon: Turtle { //declaration of inheritance
public:
    Dragon(float initX = 0.0, float initY = 0.0, float initAngle = 0.0);
    void leftCurve(int l, float d);  //draw a level-l left curve with dist d RECURSIVE FUNCTION
    void rightCurve(int l, float d); //draw a level-l right curve with dist d RECURSIVE FUNCTION
};

#endif /* Dragon_h */
