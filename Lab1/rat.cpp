// a Rational object holds one Rational number, one fraction
#ifndef RAT_CPP
#define RAT_CPP
#include "rat.h"

//------------------------------ Rational ------------------------------------
// default constructor:  parameters are numerator and denominator respectively
// if the number is negative, the negative is always stored in the numerator
Rational::Rational(int n, int d) {
   numerator = d < 0 ? -n : n;
   denominator = d < 0 ? -d : d;
   reduce();
}

//--------------------------------- add --------------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::add(const Rational& a) {
   Rational t;

   t.numerator = a.numerator * denominator + a.denominator * numerator;
   t.denominator = a.denominator * denominator;
   t.reduce();

   return t;
}
//overloaded + to add the ability to add variables normally
Rational Rational::operator+(const Rational & a) const
{
	Rational t;

	t.numerator = a.numerator * denominator + a.denominator * numerator;
	t.denominator = a.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ subtract ------------------------------------
// subtraction of 2 Rationals, current object and parameter

Rational Rational::subtract(const Rational& s) {
   Rational t;

   t.numerator = s.denominator * numerator - denominator * s.numerator;
   t.denominator = s.denominator * denominator;
   t.reduce();

   return t;
}
//overloaded - to add ability to substract variables normally
Rational Rational::operator - (const Rational & s) const{
	Rational t;

	t.numerator = s.denominator * numerator - denominator * s.numerator;
	t.denominator = s.denominator * denominator;
	t.reduce();

	return t;
}

//------------------------------ multiply ------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::multiply(const Rational& m) {
   Rational t;

   t.numerator = m.numerator * numerator;
   t.denominator = m.denominator * denominator;
   t.reduce();

   return t;
}
Rational Rational::operator*(const Rational & m) const{
	Rational t;

	t.numerator = m.numerator * numerator;
	t.denominator = m.denominator * denominator;
	t.reduce();

	return t;
}

//-------------------------------- divide ------------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero crashes
Rational Rational::divide(const Rational& v) {
   Rational t;

   t.numerator = v.denominator * numerator;
   t.denominator = denominator * v.numerator;
   t.reduce();

   return t;
}
//---------------------------- overload division operator --------------------
// overloads / to allow for regular use
Rational Rational::operator/(const Rational &v) const{
	Rational t;

	t.numerator = v.denominator * numerator;
	t.denominator = denominator * v.numerator;
	t.reduce();

	return t;
}
//---------------------------- printRational ---------------------------------
void Rational::printRational() {
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else if (numerator == 0)
      cout << 0;
   else
      cout << numerator << "/" << denominator;
}
//--------------------------- overload output stream ------------------------------------
//overloads << to allow for regular use
std::ostream& operator<<(ostream& os, const Rational& a) {
	if (a.denominator == 0) {
		os << "DIVIDE BY ZERO ERROR!!!";
	return os;
	}
	else if (a.numerator == 0) {
		os << 0;
		return os;
	}
	else {
		os << a.numerator << "/" << a.denominator;
		return os;
	}

}
//-------------------------------- overload input stream ---------------------------------------
// overloads >> to allow for regular use
std::istream& operator>>(istream& is, Rational& a) {
	cout << "Please enter numerator first:";
	is >> a.numerator;//get numerator first
	cout << "Please enter denominator:";
	is >> a.denominator;//get denominator next
	return is;
}

//------------------------ printRationalAsFloat ------------------------------
void Rational::printRationalAsFloat() {  
   if (denominator == 0)
      cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
   else
      cout << float(numerator) / float(denominator);
}
//------------------------ overload < operator ----------------------
bool Rational::operator<(const Rational &a) const{
	if (denominator < a.denominator)
		return true;
	else if (denominator == a.denominator && numerator < a.numerator)
		return true;
	else return false;
}
//------------------------ overload > operator ----------------------
bool Rational::operator>(const Rational &a) const {
	if (denominator > a.denominator)
		return true;
	else if (denominator == a.denominator && numerator > a.numerator)
		return true;
	else return false;
}
//------------------------ overload == operator ----------------------
bool Rational::operator==(const Rational &a) const {
	if (denominator == a.denominator && numerator == a.numerator)
		return true;
	else return false;
}
//------------------------ overload != operator ----------------------
bool Rational::operator!=(const Rational &a) const {
	if (denominator == a.denominator && numerator == a.numerator)
		return false;
	else return true;
}
//------------------------ overload <= operator ----------------------
bool Rational::operator<=(const Rational &a) const {
	if (denominator < a.denominator)
		return true;
	else if (denominator == a.denominator && numerator < a.numerator)
		return true;
	else if (denominator == a.denominator && numerator == a.numerator)
		return true;
	else return false;
}
//------------------------ overload >= operator ----------------------
bool Rational::operator>=(const Rational &a) const {
	if (denominator > a.denominator)
		return true;
	else if (denominator == a.denominator && numerator > a.numerator)
		return true;
	else if (denominator == a.denominator && numerator == a.numerator)
		return true;
	else return false;
}
//------------------------ overload += operator ----------------------
Rational& Rational::operator+=(const Rational &a){
	numerator = (numerator * a.denominator) + (denominator * a.numerator);
	denominator = denominator * a.denominator;
	reduce();
	return *this;
}
//------------------------ getNumerator -----------------------------
//returns the value in the numerator position
int Rational::getNumerator() const
{
	return numerator;
}
//------------------------ getDenominator -----------------------------
//returns the value in the denominator position
int Rational::getDenominator() const
{
	return denominator;
}
//------------------------- setNumerator ----------------------------
//sets the value in numerator
void Rational::setNumerator(int num) {
	numerator = num;
}
//------------------------- setDenominator ----------------------------
//sets the value in demoninator
void Rational::setDenominator(int num) {
	denominator = num;
}

//-------------------------------- reduce ------------------------------------
// reduce fraction to lowest terms
void Rational::reduce() {
   int n = numerator < 0 ? -numerator : numerator;
   int d = denominator;
   int largest = n > d ? n : d;

   int gcd = 0;                                 // greatest common divisor

   for (int loop = largest; loop >= 2; loop--)
      if (numerator % loop == 0 && denominator % loop == 0) {
         gcd = loop;
         break;
      }

   if (gcd != 0) {
      numerator /= gcd;
      denominator /= gcd;
   }
}

#endif