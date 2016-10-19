//
//  mergesortimproved.cpp
//  Program4
//
//  Created by Gregory Asher on 2/19/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#include <vector>
#include <math.h> // may need to use pow( )
using namespace std;

template <class Comparable>
void mergesortImproved( vector<Comparable> &a ) {
    vector<Comparable> tempArray( a.size( ) );

    for (int i = 1; i < a.size(); i = i * 2){ //increment by a factor of two each outside loop
        for(int left = 0; left < a.size(); left += 2*i ){ //inner for loop that separates the array into sides
            int first = left;
            int mid = left + (i-1);
            if (mid >=a.size())
                mid = a.size()-1;
            int last = left + ((2*i)-1);
            if(last >=a.size())
                last = a.size()-1;
            
            //THE FOLLOWING HAS BEEN TAKEN FROM mergesort.cpp
            //I DID NOT WRITE THE FOLLOWING JUST USING IT
            // WHY FIX WHATS NOT BROKEN
            int first1 = first; int last1 = mid;         // the left array[first1..last1]
            int first2 = mid + 1; int last2 = last;     // the right array[first2..last2]
            
            int index = first1;
            for ( ; first1 <= last1 && first2 <= last2; ++index ) // choose a smaller
                tempArray[index] = ( a[first1] < a[first2] ) ? a[first1++] : a[first2++];
            
            for ( ; first1 <= last1; ++first1, ++index )      // exhaust the left array
                tempArray[index] = a[first1];
            
            for ( ; first2 <= last2; ++first2, ++index )      // exhaust the right array
                tempArray[index] = a[first2];
            
            for ( index = first; index <= last; ++index )  // write them back to original
                a[index] = tempArray[index];
            }
        tempArray.clear();
    }
}
