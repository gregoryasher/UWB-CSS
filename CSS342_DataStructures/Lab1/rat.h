// a Rational object holds one Rational number, one fraction

#ifndef RAT_H
#define RAT_H
#include <iostream>
using namespace std;

class Rational {                           // not fully commented
public:
   Rational(int = 0, int = 1);             // default constructor
   Rational add(const Rational &);
   Rational subtract(const Rational &);
   Rational multiply(const Rational &);
   Rational divide(const Rational &);
   void printRational();
   void printRationalAsFloat();
   int getNumerator() const;
   void setNumerator(int num);
   int getDenominator() const;
   void setDenominator(int deno);
   friend ostream& operator<<(ostream&, const Rational&);
   friend istream& operator>>(istream&, Rational&);
   // arithmetic operators
   Rational operator+(const Rational &) const; // add 2 Rationals
   Rational operator-(const Rational &) const; // subtract 2 Rationals
   Rational operator*(const Rational &) const; // multiply 2 Rationals
   Rational operator/(const Rational &) const; // divide 2 Rationals
   // division by zero terminates
   // boolean comparison operators
   bool operator<(const Rational &) const; // is object > parameter?
   bool operator>(const Rational &) const; // is object < parameter?
   bool operator==(const Rational &) const; // is object == parameter?
   bool operator>=(const Rational &) const; // is object >= parameter?
   bool operator<=(const Rational &) const; // is object >= parameter?
   bool operator!=(const Rational &) const; // is object != parameter?
   // assignment operators
   Rational& operator+=(const Rational &); // current object += parameter
private:
   int numerator;
   int denominator;

   void reduce();                 // utility function, reduce to lowest terms
};

#endif

