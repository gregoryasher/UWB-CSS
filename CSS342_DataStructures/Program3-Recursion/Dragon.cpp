//
//  Dragon.cpp
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

#include "Dragon.h"

//------------------------- Dragon Arrowhead ----------------------------
Dragon::Dragon(float initX, float initY, float initAngle)
:Turtle(initX, initY, initAngle) {
}

//------------------------------ leftCurve ----------------------------------
// draw a level-l left curve with dist d
// recursively calls upon itself until level = zero then it draws a straight line
// after the drawing of the line it returns to the previous recursive call, continuing
// with the previous level's call.
void Dragon::leftCurve(int level, float d) {
    if (level > 0) {
        leftCurve(level - 1, d);
        turn(90);
        rightCurve(level - 1, d);
        turn(90);
    }
    else
        draw(d);
}

//------------------------------ rightCurve ---------------------------------
// draw a level-l right curve with dist d
// recursively calls upon itself until level = zero then it draws a straight line
// after the drawing of the line it returns to the previous recursive call, continuing
// with the previous level's call.
void Dragon::rightCurve(int level, float d) {
    if (level > 0) {
        turn(-90);
        leftCurve(level - 1, d);
        turn(-90);
        rightCurve(level - 1, d);
    }
    else
        draw(d);
}
