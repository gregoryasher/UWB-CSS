//
//  main.cpp
//  Program2
//
//  Created by Gregory Asher on 1/29/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//
#include "Euclid.h"
using namespace std;

int main() {
    Euclid largest(1,1);//initialize keeper variable
    int n;//initialize input value n
    struct timeval start, end;
    cout<<"Please enter a value for n" << endl;
    cin>>n;
    gettimeofday(&start, NULL);
    for(int i = 8; i < n + 1; i++){
        for(int j = 1; j<i; j++){
            Euclid test(j,i);
            if (test.getOperationCount() > largest.getOperationCount())//if the GCD loops run more times than 1 time, set the largest to be the test
                largest = test;
        }
        //print the data in a clear and easy to understand format
        gettimeofday(&end, NULL);
        float totaltime =((end.tv_sec - start.tv_sec)* 1000.0f) + (end.tv_usec - start.tv_usec)/1000.0f;
        cout << "At i = " << i << "; gcd (" << largest.getPartA()<< "," << largest.getPartB() << ") = "
            << largest.getGCDValue() << " took "  << largest.getOperationCount() << " operations."
            << " Completed in: " << totaltime << " milliseconds" <<endl;
    }
    return 0;
}

