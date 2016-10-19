#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex
{
public:
	//default constructor sets both coefficients to zero
	Complex(double = 0.0, double = 0.0);
	double getReal() const; //returns the real part of the equation
	double getImaginary() const; //returns the coefficient corresponding to the non real part of i
	double abs() const; // returns the absolute value for a given function
	Complex conjugate() const; //returns the conjugate of an complex number
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	// arithmetic operators
	Complex operator+(const Complex &) const;   // add 2 Rationals
	Complex operator-(const Complex &) const;   // subtract 2 Rationals
	Complex operator*(const Complex &) const;   // multiply 2 Rationals
	Complex operator/(const Complex &) const;   // divide 2 Rationals
	Complex& operator+=(const Complex &);   // add 2 Rationals and set equals to original
	Complex& operator-=(const Complex &);   // subtract 2 Rationals and set equals to original
	Complex& operator*=(const Complex &);   // multiply 2 Rationals and set equals to original
	Complex& operator/=(const Complex &);   // division by 2 and set equals to original
	bool operator==(const Complex &) const; //boolean equals to
	bool operator!=(const Complex &) const; //boolean not equals to

	//~Complex();
private:
	double realNum;
	double imagNum;

};
#endif
