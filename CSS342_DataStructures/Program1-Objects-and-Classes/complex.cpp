#include "math.h"
#include "complex.h"
//constructor accepts 1, 2, or no parameters
Complex::Complex(double x, double y){
	realNum = x;
	imagNum = y;
}
//getter for imaginary coefficient
double Complex::getImaginary() const{
	return this->imagNum;
}
//Getter for the real portion
double Complex::getReal() const {
	return this->realNum;
}
//----------ABSOLUTE VALUE FUNCTION------------
double Complex::abs() const {
	//Need: square_root(x^2 + y^2)
	//or square_root(real^2 + imaginary^2)
	double d;
	d = (realNum * realNum) + (imagNum * imagNum);
	d = sqrt(d);
	return d;
}
//----------------------OVERLOAD EQUALS TO BOOLEAN OPERATOR-------------------------
bool Complex::operator==(const Complex &com) const {
	if (com.realNum == this->realNum && com.imagNum == this->imagNum)
		return true;
	else return false;
}
//----------------------OVERLOAD NOT EQUALS TO BOOLEAN OPERATOR-------------------------
bool Complex::operator!=(const Complex &com) const {
	if (com.realNum == this->realNum && com.imagNum == this->imagNum)
		return false;
	else return true;
}
//----------------------OVERLOAD ADDITION OPERATOR-------------------------
Complex Complex::operator+(const Complex &a) const {
	Complex sum;
	sum.realNum = a.realNum + this->realNum;
	sum.imagNum = a.imagNum + this->imagNum;
	return sum;
}
//----------------------OVERLOAD SUBTRACTION OPERATOR-------------------------
Complex Complex::operator-(const Complex &s) const {
	Complex diff;
	diff.realNum = this->realNum - s.realNum;
	diff.imagNum = this->imagNum - s.imagNum;
	return diff;
}
//----------------------OVERLOAD MULTIPLICATION OPERATOR-------------------------
Complex Complex::operator*(const Complex &m) const {
	Complex mult;
	//Need to consider:
	// (a+bi)(x+yi) where when factored you should arrive to
	// = [ax + ayi + bxi + byi^2] which simplifies to 
	// = [ax + (bx + ay)i - by] which simplifies again to
	// = (ax-by) + (bx+ay)i
	mult.realNum = (m.realNum * this->realNum) - (m.imagNum * this->imagNum);
	mult.imagNum = (m.realNum * this->imagNum) + (this->realNum * m.imagNum);
	return mult;
}
//----------------------OVERLOAD PLUS EQUALS OPERATOR-------------------------
//This part gave me hell because I forgot the ampersand after the first Complex declaration.
Complex& Complex::operator+=(const Complex &a) {
	this->realNum = a.realNum + this->realNum;
	this->imagNum = a.imagNum + this->imagNum;
	return *this;
}
//----------------------OVERLOAD SUBTRACTION EQUALS OPERATOR-------------------------
Complex& Complex::operator-=(const Complex &s) {
	realNum = this->realNum - s.getReal();
	imagNum = this->imagNum - s.getImaginary();
	return *this;
}
//----------------------OVERLOAD MULTIPLICATION EQUALS OPERATOR-------------------------
Complex& Complex::operator*=(const Complex &m) {
	//Need to consider:
	// (a+bi)(x+yi) where when factored you should arrive to
	// = [ax + ayi + bxi + byi^2] which simplifies to 
	// = [ax + (bx + ay)i - by] which simplifies again to
	// = (ax-by) + (bx+ay)i
	this->realNum = (m.realNum * this->realNum) - (m.imagNum * this->imagNum);
	this->imagNum = (m.realNum * this->imagNum) + (this->realNum * m.imagNum);
	return *this;
}
//----------------------OVERLOAD DIVISION EQUALS OPERATOR-------------------------
Complex& Complex::operator/=(const Complex &d) {
	if (d.imagNum == 0 && d.realNum == 0) {
		cout << "Error Divide by Zero. Returning numerator." << endl;
		return *this;
	}
		/*Need to consider:
		a+bi / x+yi
		In order do do this operation must multiply by conjugate of denominator
		Conjugate of denominator means multiplying imaginary part by -1
		Thus the conjugate of x+yi == x-yi
		final result of the division should be as follows:
		[(ax + by) + (bx - ay) * i] / (x^2 + y^2)
		simplified gives:
		REAL							IMAGINARY
		(ax + by) / (x^2 + y^2)		+		[(bx - ay) / (x^2 + y^2)] * i
		REAL							IMAGINARY
		*/
		this->realNum = (this->realNum * d.realNum) + (this->imagNum * d.imagNum);
		this->realNum = this->realNum / ((d.realNum * d.realNum) + (d.imagNum * d.imagNum));
		this->imagNum = (this->imagNum * d.realNum) - (this->realNum * d.imagNum);
		this->imagNum = this->imagNum / ((d.realNum * d.realNum) + (d.imagNum * d.imagNum));
	return *this;
}
//----------------------OVERLOAD DIVISION OPERATOR-------------------------
Complex Complex::operator/(const Complex &d) const {
	Complex divide;
	if (d.imagNum == 0 && d.realNum == 0) {
		cout << "Error Divide by Zero. Returning Numerator." << endl;
		return *this;
	}
		/*Need to consider:
								a+bi / x+yi
		In order do do this operation must multiply by conjugate of denominator
		Conjugate of denominator means multiplying imaginary part by -1
		Thus the conjugate of x+yi == x-yi
		final result of the division should be as follows:
					[(ax + by) + (bx - ay) * i] / (x^2 + y^2)
		simplified gives:
								REAL							IMAGINARY
					(ax + by) / (x^2 + y^2)		+		[(bx - ay) / (x^2 + y^2)] * i
								REAL							IMAGINARY
		*/
		divide.realNum = (this->realNum * d.realNum) + (this->imagNum * d.imagNum);
		divide.realNum = divide.realNum / ((d.realNum * d.realNum) + (d.imagNum * d.imagNum));
		divide.imagNum = (this->imagNum * d.realNum) - (this->realNum * d.imagNum);
		divide.imagNum = divide.imagNum / ((d.realNum * d.realNum) + (d.imagNum * d.imagNum));
	return divide;
}
//----------------------OVERLOAD OUTPUT OPERATOR-------------------------
ostream& operator<<(ostream &output, const Complex &comp) {
	/*Complicated if protocal for overloading the output
	first IF: if the real part is zero AND if the imaginary part is NOT zero,
	AND if the imaginary part is NOT one AND if the imaginary part is NOT negative one:
	print the imaginary coefficient and the letter i
	*/
	if (comp.realNum == 0 && comp.imagNum != 0 && comp.imagNum != 1 && comp.imagNum != -1) {
		output << comp.imagNum << "i";
	}
	/*ELSE IF 
	Real part is NOT zero AND the imaginary part IS EQUALS TO zero
	print ONLY the real part
	*/
	else if (comp.realNum != 0 && comp.imagNum == 0) {
		output << comp.realNum;
	}	
	/*ELSE IF
	Real part IS EQUALS TO zero AND imaginary part IS EQUALS TO one
	print ONLY THE LETTER i
	*/
	else if (comp.realNum == 0 && comp.imagNum == 1) {
		output << "i";
	}
	/*ELSE IF
	Real part NOT zero AND imaginary part EQUALS TO 1
	print real value AND plus symbol AND the letter i
	*/
	else if (comp.realNum != 0 && comp.imagNum == 1) {
		output << comp.realNum << "+" << "i";
	}
	/*ELSE IF
	Real part NOT zero AND imaginary part EQUALS TO negative one
	print real value AND negative sign i
	*/
	else if (comp.realNum != 0 && comp.imagNum == -1) {
		output << comp.realNum << "-i";
	}
	/*ELSE IF
	Real part EQUALS TO zero AND imaginary part EQUALS TO negative one
	print ONLY negative sign i
	*/
	else if (comp.realNum == 0 && comp.imagNum == -1) {
		output << "-i";
	}
	/*ELSE IF
	Real part NOT EQUALS to zero AND imaginary part NOT EQUALS to zero AND imaginary part greater than zero
	print real part AND plus sign AND imaginary part AND the letter i
	*/
	else if (comp.realNum != 0 && comp.imagNum != 0 && comp.imagNum > 0) {
		output << comp.realNum << "+" << comp.imagNum << "i";
	}
	/*ELSE IF
	Real part NOT EQUALS to zero AND imaginary part NOT EQUALS to zero AND imaginary part LESS THAN zero 
	BUT NOT EQUALS TO negative 1
	print real value AND imaginary value AND the letter i
	NOTE THAT YOU DO NOT NEED TO PRINT NEGATIVE SIGN AS THE NEGATIVE VALUE WILL TAKE CARE OF THIS FOR YOU
	*/
	else if (comp.realNum != 0 && comp.imagNum != 0 && comp.imagNum < 0 && comp.imagNum != -1) {
		output << comp.realNum << comp.imagNum << "i";
	}
	/*ELSE IF BOTH VALUES ARE EQUAL TO ZERO
	print ONLY zero
	*/
	else if (comp.realNum == 0 && comp.imagNum == 0) {
		output << 0;
	}
	return output;
}
//--------------OVERRIDE INPUT-----------------
//accepts two inputs, one for the real, one for the imaginary. 
//ASSUME FIRST YOU'RE PROVIDED A REAL THEN AN IMAGINARY
istream& operator>>(istream &input, Complex &comp) {
	input >> comp.realNum >> comp.imagNum;
	return input;
}
//------------conjugate-------------------
//EXPLAINATION CONTAINED WITHIN
Complex Complex::conjugate() const{
	Complex conj;
	//conjugate of a + bi = a - bi;
	//conjugate of a - bi = a + bi;
	conj.imagNum = this->imagNum *(-1);
	conj.realNum = this->realNum;
	return conj;
}
