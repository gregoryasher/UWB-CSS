//
//  polynomial.cpp
//  Program1
//
//  Created by Gregory Asher on 3/30/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#include "polynomial.h"
#include "cmath"
/*------------------------Default constructor with no arguments--------------------------
 sets the value of coefficient to zero thus only giving zero
 */
Polynomial::Polynomial(){
    head = new Term;
    head->next = new Term;
    head->prev = new Term;
    head->next = NULL;
    head->prev = NULL;
    size = 0;
}
/*-------------------------------------Copy Constructor---------------------------------------
 Populates the new Polynomial object with a deep copy of the passed Polynomial object
 */
Polynomial::Polynomial(const Polynomial& p){
    head = new Term;
    head->next = new Term;
    head->prev = new Term;
    head->next = NULL;
    head->prev = NULL;
    size = 0;
    Term *cur = p.head->next;
    while(cur != p.head && cur != NULL){
        changeCoefficient(cur->coeff, cur->power);
        cur = cur->next;
    }
    
}
/*-------------------------------------Destructor---------------------------------------
 Goes through node by node setting the values to NULL 
 then deletes the cursor and head
 */
Polynomial::~Polynomial(){
    Term *current = head->next;
    while (current != NULL && current != head){
        remove(current);
        current = current->next;
    }
}

std::ostream& operator<<( ostream &output, const Polynomial& p ){
    if (p.head->next == NULL || p.head->next->next == p.head){
        output << "0.0";
        return output;
    }
    
    Polynomial::Term *cur = p.head->next;
    output << cur->coeff << "x^" << cur->power;
    cur = cur->next;
    while (cur != p.head){
        if (cur->power == 0){
            if (cur->coeff < 0){
                output << " - " << cur->coeff;
            }
            else{
                output << " + " << cur->coeff;
            }
        }
        else if (cur->coeff < 0)
            output << " - " << abs(cur->coeff) << "x^" << cur->power;
        else if (cur->coeff > 0)
            output << " + " << abs(cur->coeff) << "x^" << cur->power;
        cur = cur->next;
    }
    return output;
}
/*------------------------Getter for Degree of Polynomial object--------------------------
 obtains the highest power which should be at the start of the list because it's a sorted list.
 */
int Polynomial::degree() const{
    //if both head and head->next have power zero, its a blank list. return 0
    if (head->next == NULL)
        return 0;
    else return head->next->power; //its a sorted list, therefore the next term should have highest power
}
/*------------------------Getter for Coefficient of Polynomial object--------------------------
 circulates through polynomial object and obtains the coefficient of the desired power
 first checks to see if the list is empty.
  */
double Polynomial::coefficient(const int power) const{
    if(head->next == NULL)
        return 0; //blank list;
    Term *cur = head->next;
    while(cur!=head){
        if (cur->power == power)
            return cur->coeff;
        cur = cur->next;
    }
    return 0.0; //object not found
}
/*------------------------------------- Change Coefficient ---------------------------------------
 Adds the term to the list if it doesn't exist yet, if it does exist
 changes the coefficient to the new value.
 if the new value is 0, removes the term from the list.
 */
bool Polynomial::changeCoefficient( const double newCoefficient, const int power ){
    if (head->next == NULL){
        return insert(head, newCoefficient, power);
    }
    Term *cur = head->next;
    while (cur!=head){ //check to see if the power exists by going through the list
        if (cur->power == power){
            if (newCoefficient == 0.0){
                remove(cur);
            }
                cur->coeff = newCoefficient;
                return true;
        }
        else if (power > cur->power){
            if (newCoefficient == 0.0){
                remove(cur);
            }
            return insert(cur, newCoefficient, power);
        }
        cur = cur->next;
    }
    return insert(head, newCoefficient, power);
}
/*------------------------------------- Addition  ---------------------------------------
 Checks to see if both lists are null, if null return nothing.
 iterates through the list until back to the beginning.
 if the powers of the two sides are equal, add the coefficients
 if one side is larger than the other, *this polynomial does not contain this term
 add it to *this polynomial
 if reached end of polynomial but the other polynomial still has more terms
 add them to *this polynomial
 */
Polynomial Polynomial::operator+( const Polynomial& p ) const{
    //first check to see if everything or one thing is null
    if(head->next == NULL && p.head->next == NULL)
        return *this;
    else if (head->next == NULL)
        return p;
    else if (p.head->next == NULL)
        return *this;
    
    Polynomial retVal;
    Term *leftCur = head->next;
    Term *rightCur = p.head->next;
    
    while (leftCur != head || rightCur != p.head){
        if (leftCur->power == rightCur->power){
            retVal.changeCoefficient( (leftCur->coeff+rightCur->coeff) , leftCur->power);
            leftCur = leftCur->next;
            rightCur = rightCur->next;
        }
        else if (leftCur->power > rightCur->power){
            retVal.changeCoefficient(leftCur->coeff, leftCur->power);
            leftCur = leftCur->next;
        }
        else if (leftCur->power < rightCur->power){
            retVal.changeCoefficient(rightCur->coeff, rightCur->power);
                rightCur = rightCur->next;
        }
        else if (rightCur == p.head){
            retVal.changeCoefficient(leftCur->coeff, leftCur->power);
            leftCur = leftCur->next;
        }
        else if (leftCur == head){
            retVal.changeCoefficient(rightCur->coeff, rightCur->power);
            rightCur = rightCur->next;
        }
    }
    //cout << "RETURNING VALUE " << retVal << endl;
    return retVal;
}
/*------------------------------------- Subtraction  ---------------------------------------
 checks to see if both Polynomials are empty first
 checks to see if they're equal, if equal returns an empty polynomial (0)
 creates a new Polynomial, adds all of p's Term's with coeff multiplied by -1 to new Polynomial
 Uses the addition function to add them together.
 */
Polynomial Polynomial::operator-( const Polynomial& p ) const{
    //first check to see if everything or one thing is null
    if(this->head == NULL && p.head == NULL)
        return *this;
    else if (this->head == NULL)
        return p;
    else if (p.head == NULL)
        return *this;
    Polynomial retVal;
    if (*this==p){
        return retVal;
    }
    Term *rightCur = p.head->next;
    while (rightCur != p.head){
        retVal.changeCoefficient( rightCur->coeff * -1, rightCur->power);
        rightCur = rightCur->next;
    }
    return *this + retVal;
}
/*------------------------------------- Boolean EqualsEquals  ---------------------------------------
 checks to see if they're both null return true, or if only one is null, return false;
 checks to see if they're both empty, return true, or if only one is empty, return false;
 checks to see if both lists have the same degree first, if not return false, impossible to be equal;
 iterates through each, if they're
 */
bool Polynomial::operator==( const Polynomial& p ) const{
    if(head == NULL || p.head == NULL){
        if (head == NULL && p.head == NULL)
            return true;
        else return false;
    }
    if (head->next == NULL || p.head->next == NULL){
        if(head->next == NULL && p.head->next == NULL)
            return true;
        else return false;
    }
    if (this->degree() != p.degree()) //if the degrees arent equal its not possible for them to be equal
        return false;
    Term *leftCur = head->next;
    Term *rightCur = p.head->next;
    while (leftCur != head || rightCur != p.head){
        if (leftCur->power == rightCur->power){
            if (leftCur->coeff == rightCur->coeff){
                rightCur = rightCur->next;
                leftCur = leftCur->next;
                continue;
            }
            else return false;
        }
        if (leftCur->next == NULL || rightCur->next == NULL){
            if (leftCur->next == NULL && rightCur->next == NULL)
                return true;
            else return false;
        }
    }
    return true;
}
/*------------------------------------- Boolean NotEquals  ---------------------------------------
 returns !(==) because its basically just the false of if they are equal.
 */
bool Polynomial::operator!=( const Polynomial& p ) const{
    return !(*this == p);
}
/*------------------------------------- Declarator Equals  ---------------------------------------
 first check to see if they're equal, if they're equal don't do anything: return *this;
 otherwise delete everything in this, set *this = p return *this;
 */
Polynomial& Polynomial::operator=( const Polynomial& p ){
    if (*this == p){
        return *this;
    }
    Term *cur = head->next;
    while(cur != head && cur != NULL){
        this->remove(cur);
        cur = head->next;
    }
    if (p.head->next == NULL)
        return *this;
    Term *newCur;
    newCur = p.head->next;
    while(newCur != p.head && newCur != NULL){
        this->changeCoefficient(newCur->coeff, newCur->power);
        newCur = newCur->next;
    }
    return *this;
}
/*------------------------------------- Declarator PlusEquals  ---------------------------------------
 Checks to see if either or both lists are null, if so, return
 uses the addition function to return the added summary
 */
Polynomial& Polynomial::operator+=( const Polynomial& p ){
    if(this->head == NULL && p.head == NULL)
        return *this;
    else if (this->head == NULL)
        return *this;
    else if (p.head == NULL)
        return *this;
    *this = *this + p;
    return *this;
}
/*------------------------------------- Declarator MinusEquals  ---------------------------------------
 Checks to see if either or both lists are null, if so, return
 uses the subtraction function to return the added summary
 */
Polynomial& Polynomial::operator-=( const Polynomial& p ){
    *this = *this-p;
    return *this;
}
/*------------------------------------- Remove  ---------------------------------------
 check to see if you're being sent a null pointer, if so, return false ->basically an error
 check to see if you're given the only node left
 if so, reallocate the pointers to default NULL position
 delete pos;
 set pos to null;
 if this isnt the case just reallocate the pointers
 delete pos
 set pos to null;
 decrement size;
 */
bool Polynomial::remove( Term* pos ){
    if(pos == NULL || pos->next == NULL)
        return false;
    else if(pos->next->next == pos){
        pos->prev->next = NULL;
        pos->next->prev = NULL;
        delete pos;
        pos = NULL;
        size --;
        return true;
    }
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    pos = NULL;
    size --;
    return true;
}
/*------------------------------------- Insert  ---------------------------------------
 assumes that the term being passed in is the next lowest degree polynomial
 inserts in front of this position.
 increments size;
 */
bool Polynomial::insert( Term* previous, const double newCoefficient, const int power ){
    Term *newPoly = new Term;
    newPoly->power = power;
    newPoly->coeff = newCoefficient;
    newPoly->next = previous;
    if(previous->next == NULL){
        newPoly->prev = previous;
        previous->next = newPoly;
    }
    else{
        newPoly->prev = previous->prev;
        previous->prev->next = newPoly;
    }
    previous->prev = newPoly;
    size++;
    return true;
}

