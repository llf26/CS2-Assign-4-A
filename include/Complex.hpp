#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <string>
#include <fstream>

class Complex
{
public:
   Complex(double = 0.0, double = 0.0); // default constructor
   Complex add(const Complex&) const;			  // function add
   Complex subtract(const Complex&) const; // function subtract
   Complex multiply(const Complex&) const; // function multiply
   std::string toString() const;  // return string representation
   void setComplexNumber(double, double); // set complex number

 //Friend functions that overload insertion and extraction operators to display/take
 //in complex numbers
   friend std::ostream& operator<<(std::ostream& os, const Complex& obj);
   friend std::istream& operator>>(std::istream& is, Complex& obj);

//Overloaded Operator Function Definitions
  void operator=(const Complex& obj)
  {
      //Set real and imaginary parts of left hand side to those of the right hand side
      (*this).realPart = obj.realPart;
      (*this).imaginaryPart = obj.imaginaryPart;

  }

  Complex operator+(const Complex& obj)
  {
     //Add real and imaginary parts of right hand side to left hand side
      Complex tmp_obj = *this;
      tmp_obj.realPart = tmp_obj.realPart + obj.realPart;
      tmp_obj.imaginaryPart = tmp_obj.imaginaryPart + obj.imaginaryPart;
      return tmp_obj;
  }

  Complex operator-(const Complex& obj)
  {
     //Subtract real and imaginary parts of right hand side from left hand side
      Complex tmp_obj = *this;
      tmp_obj.realPart = tmp_obj.realPart - obj.realPart;
      tmp_obj.imaginaryPart = tmp_obj.imaginaryPart - obj.imaginaryPart;
      return tmp_obj;
  }

  Complex operator*(const Complex&obj)
  {
      //Implementation of the FOIL process for (a + bi)(a + bi)

      Complex tmpObj = *this;
      double temp = tmpObj.realPart;
      tmpObj.realPart = (tmpObj.realPart * obj.realPart) - (tmpObj.imaginaryPart * obj.imaginaryPart);
      tmpObj.imaginaryPart = (temp  * obj.imaginaryPart) + (tmpObj.imaginaryPart * obj.realPart);
      return tmpObj;
  }

  bool operator==(const Complex& obj)
  {
      //Compare both the real and imaginary parts of each side
      Complex tmpObj = *this;
      if((tmpObj.realPart == obj.realPart) && (tmpObj.imaginaryPart == obj.imaginaryPart))
        return true;
      else
        return false;
  }

  bool operator!=(const Complex& obj)
  {
      //Compare both the real and imaginary parts of each side
      Complex tmpObj = *this;
      if((tmpObj.realPart != obj.realPart) && (tmpObj.imaginaryPart != obj.imaginaryPart))
        return true;
      else return false;
  }




private:
   double realPart;
   double imaginaryPart;
};

#endif
