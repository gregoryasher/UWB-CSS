//
//  driver.cpp
//  Program1
//
//  Created by Gregory Asher on 3/30/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#include <iostream>

#include <iostream>
using namespace std;

#include "polynomial.h"

int main( )

{
    
    Polynomial p1;
    cout << "p1 = " << p1 << endl << endl;
    p1.changeCoefficient( 4, 4 );
    p1.changeCoefficient( 2, 2 );
    p1.changeCoefficient( -3, 3 );
    cout << "p1 = " << p1 << endl;
    cout << "p1.changeCoeff( 0 , 2 ) " << endl;
    p1.changeCoefficient( 0, 2 );
    cout << "p1 = " << p1 << endl << endl;
    
    cout << "Now creating p2!" << endl;
    Polynomial p2;
    p2.changeCoefficient(8, 8);
    p2.changeCoefficient(7, 7);
    p2.changeCoefficient(6, 6);
    p2.changeCoefficient(5, 5);
    p2.changeCoefficient(4, 4);
    p2.changeCoefficient(3, 3);
    p2.changeCoefficient(2, 2);
    p2.changeCoefficient(1, 1);
    cout << "p2 = " << p2 << endl << endl;
    
    cout << "p2.changeCoeff( 0 , 5 ) " << endl;
    p2.changeCoefficient(0, 5);
    cout << "p2 = " << p2 << endl << endl;
    
    cout << "p2 - p1 = " << p2 - p1 << endl;
    cout << "p2 = " << p2 << endl; //check to make sure they stayed the same
    cout << "p1 = " << p1 << endl << endl;
    
    cout << "Set p2 = p1" << endl;
    p2 = p1;
    cout << "p2 = " << p2 << endl;
    cout << "p1 = " << p1 << endl << endl;
    
    cout << "p1 - p1 = " << p1-p1 << endl;
    p2.changeCoefficient( 9.5, 2 );

    cout << "p2 = " << p2 << endl;
    cout << "now creating p3 = p1 + p2;" << endl;
    Polynomial p3 = p1 + p2;
    cout << "p3 = " << p3 << endl;
    
}