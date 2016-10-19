//
//  partialsort.cpp
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

#include <stdio.h>
#include <vector>

using namespace std;

template <class Comparable>
void objectSwap( Comparable &lhs, Comparable &rhs ) {
    Comparable tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template <class Comparable>
void choosePivot( vector<Comparable> &a, int first, int last ) {
    int middle = ( first + last ) / 2;
    objectSwap( a[first], a[middle] );
}

template <class Comparable>
void partition( vector<Comparable> &a, int first, int last, int &pivotIndex ){
    // place the pivot in a[first]
    choosePivot( a, first, last );
    Comparable pivot = a[first];
    int lastS1 = first;
    int firstUnknown = first + 1;
    
    for ( ; firstUnknown <= last; ++firstUnknown ) {
        if ( a[firstUnknown] < pivot ) {
            ++lastS1;
            objectSwap( a[firstUnknown], a[lastS1] );
        }
        // else item from unknown belongs in S2
    }
    // decide a new pivot
    objectSwap( a[first], a[lastS1] );
    pivotIndex = lastS1;
}

template <class Comparable>
void quicksort( vector<Comparable> &a, int first, int last, int bottomK ) {
    int pivotIndex;
    if (a[(a.size()-1) - bottomK] > first || a[a.size()-1] < last)
        partition(a, first, last, pivotIndex);
    
    if ( first < last ) {
        partition( a, first, last, pivotIndex );
        quicksort( a, first, pivotIndex - 1, bottomK);
        quicksort( a, pivotIndex + 1, last, bottomK );
    }
}

template <class Comparable>
void partialsort( vector<Comparable> &a, int bottomK){
    quicksort(a, 0, a.size()-1, bottomK);
}

template <class Comparable>
void quicksort( vector<Comparable> &a ) {
    quicksort( a, 0, a.size( ) - 1 );
}


