//
//  main.cpp
//  Lab4
//
//  Created by Gregory Asher on 2/4/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//
/*
 NOTES:
 STUDENT ID NO: 1566775
 1566775 % 3 = 1
 THUS PROGRAM ASSIGNMENT: BOTTOM 10
 
 Code gives correct output, Peices of the array beforehand are still unsorted.
 Unsure on requirements for how much should remain unsorted.
 
 -----DETAILS ON partialsort.cpp-----
 
 I created a partial sort that has an upper and lower bound that when not met
 repartitions. I designed this based off of my work on the exam attempting to figure it out.
 
 Appears to work, but most of the rest of the array appears sorted. Although, most isn't all.
 Several numbers are still out of place when using this method.
 
 I am unclear on how sorted the final result must look. This program partially sorts the array
 and gathers the information requested.
 
 -----DETAILS ON main.cpp-----
 
 MODIFICATIONS:
 I modified the main method to display both the before sorted array, and subsequently the
 post sorting. If you read through my main you will also find a full print out of the
 sorted array block commented out. This was used for my debugging. I was trying to see
 what each change in the code that I made had an effect on. I have chosen to display
 the integers with spaces between them for readability and have them end lines after each
 print, also for readability.
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "partialsort.cpp"
using namespace std;

// initialize a given array with random numbers.
void initArray( vector<int> &array, int randMax ) {
    int size = array.size( );
    
    for ( int i = 0; i < size; ) {
        int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
        bool hit = false;
        for ( int j = 0; j < i; j++ ) {
            if ( array[j] == tmp ) {
                hit = true;
                break;
            }
        }
        if ( hit )
            continue;
        array[i] = tmp;
        i++;
    }
}

int main( int argc, char* argv[] ) {
    // verify arguments. if you find the median, no need of topK where argc == 2
    if ( argc != 3 ) {
        cerr << "usage: ./a.out size topK" << endl;
        return -1;
    }
    
    // verify an array size
    int size = atoi( argv[1] );
    if ( size <= 0 ) {
        cerr << "array size must be positive" << endl;
        return -1;
    }
    
    // verify top/bottom k. if you find the median, no need of the next 4 lines
    int topK = atoi( argv[2] );
    if ( topK <= 0 ) {
        cerr << "topX must be positive" << endl;
        return -1;
    }
    
    // array generation
    srand( 1 );
    vector<int> items( size );
    initArray( items, size );
    
    // partial quicksort. if you find the median, no need of the 2nd argument.
    cout<< "Before sorting: " << endl;
    for(int i = 0; i<items.size()-1; i++)
        cout << items[i] << " ";
    cout<<endl;
    
   /* //display the array quicksorted.
    vector<int> copied = items;
    quicksort(copied);
    cout<< "Quicksorted: " << endl;
    for(int i = 0; i<copied.size()-1; i++)
        cout << copied[i] << " ";
    cout<<endl;
    */
    partialsort( items, topK);
    //print out entire array partially sorted here
    cout << "Partial sort " << endl;
    for(int i = 0; i<items.size()-1; i++)
        cout << items[i] << " ";
    cout<<endl;
    // print out the bottom 10 partial sorted here.
    cout << "Bottom 10 in acending order: " << endl;
    for(int i = items.size()-11; i<items.size()-1; i++)
        cout << items[i] << " ";
    cout<<endl;
    return 0;
}
