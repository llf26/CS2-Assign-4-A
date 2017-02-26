// Member-function definitions for class Complex.
#include <iostream>
#include <sstream> // for ostringstream class
#include "Complex.hpp"

Complex::Complex(double real, double imaginary)
   : realPart(real), imaginaryPart(imaginary) { }

Complex Complex::add(const Complex &right) const
{
   return Complex(
      realPart + right.realPart, imaginaryPart + right.imaginaryPart);
}

Complex Complex::subtract(const Complex &right) const
{
   return Complex(realPart - right.realPart, imaginaryPart - right.imaginaryPart);
}

Complex Complex::multiply(const Complex &right) const
{
   return Complex((realPart * right.realPart) - (imaginaryPart * right.imaginaryPart),
                  (imaginaryPart * right.imaginaryPart) + (realPart * right.realPart));
}

std::string Complex::toString() const
{
   std::ostringstream output;
   output << "(" << realPart << ", " << imaginaryPart << ")";
   return output.str();
}

void Complex::setComplexNumber(double rp, double ip)
{
   realPart = rp;
   imaginaryPart = ip;
}

//Overloaded Operator Function Definitions


  std::ostream& operator<<(std::ostream& os, const Complex& obj)
  {
      os << "(" << obj.realPart << ", " << obj.imaginaryPart << ")";
      return os;
  }

  std::istream& operator>>(std::istream& is, Complex& obj)
  {

      is >> obj.realPart >> obj.imaginaryPart;
      return is;
  }


