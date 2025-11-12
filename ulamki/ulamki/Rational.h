#pragma once
#include <iostream>
using namespace std;

class Rational
{
public:
  Rational( int num = 0, int denum = 1 ); // konstruktor z parametrami domyslnymi, licznik 0, mianownik 1
  Rational( const Rational& r ); // konstrukltor kopiujacy
  virtual ~Rational();

  Rational& operator = (const Rational& r); // operator podstawienia

  //---Settery------------------
  void SetNumerat(int Num);
  void SetDenominant(int Denum);
  void setRational(int num, int denum);

  //---Gettery------------------
  int GetNumerat() const;
  int GetDenominat() const;

  //--Operatory-----------------
  friend const Rational operator + (const Rational& r1, const Rational& r2);
  friend const Rational operator - (const Rational& r1, const Rational& r2);
  friend const Rational operator * (const Rational& r1, const Rational& r2);
  friend const Rational operator / (const Rational& r1, const Rational& r2);

  Rational& operator += (const Rational& r);
  Rational& operator -= (const Rational& r);
  Rational& operator *= (const Rational& r);
  Rational& operator /= (const Rational& r);

  friend istream& operator >> (istream& in, Rational& r);
  friend ostream& operator << (ostream& out, const Rational& r);

  //--Funkcje------
public:
  double Value() const;

private:
  void reduce(); 
  int NWD(int a, int b); 

private:
  int mNumerator;
  int mDenominator;
};

//---INLINE----------

inline void Rational::SetNumerat(int Num) 
{
  mNumerator = Num;
  reduce();
}

inline void Rational::SetDenominant(int Denum)
{
  if( !Denum ) {
    cerr << "ERROR: division by zero !! in SetDenominant" << endl << endl;
    Denum = 1;
  }
  mDenominator = Denum;
  reduce();
}

inline void Rational::setRational(int num, int denum)
{
  if( !denum ) {
    cerr << "ERROR: division by zero !! in setRational" << endl << endl;
    denum = 1;
  }
  mNumerator = num;
  mDenominator = denum;
  reduce();
}

inline int Rational::GetNumerat() const
{
  return this->mNumerator;
}

inline int Rational::GetDenominat() const 
{
  return this->mDenominator;
}
 
inline double Rational::Value() const 
{
  return static_cast<double>(mNumerator) / mDenominator;
}