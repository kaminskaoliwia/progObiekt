#include "Rational.h"

Rational::Rational( int num/* = 0 */, int denum/* = 1 */)
{
  setRational(num, denum);
}

Rational::Rational( const Rational& r )
{
  mNumerator = r.mNumerator;
  mDenominator = r.mDenominator;
}

Rational::~Rational()
{}

Rational& Rational::operator = (const Rational& r)
{
  if( this != &r )
  {
    mNumerator = r.mNumerator;
    mDenominator = r.mDenominator;
  }

  return *this;
}

const Rational operator + (const Rational& r1, const Rational& r2)
{
  Rational res= r1;
  return res += r2;
}

const Rational operator - (const Rational& r1, const Rational& r2)
{
  Rational res( r1 );
  return res -= r2;
}

const Rational operator * (const Rational& r1, const Rational& r2)
{
  Rational res( r1 );
  return res *= r2;
 }

const Rational operator / (const Rational& r1, const Rational& r2)
{
  Rational res( r1 );
  return res /= r2;
}

Rational& Rational::operator += (const Rational& r)
{
  mNumerator = mNumerator * r.mDenominator + r.mNumerator * mDenominator;
  mDenominator = mDenominator * r.mDenominator;
  reduce();
  return *this;
}

Rational& Rational::operator -= (const Rational& r)
{
  mNumerator = mNumerator * r.mDenominator - r.mNumerator * mDenominator;
  mDenominator = mDenominator * r.mDenominator;
  reduce();
  return *this;
}

Rational& Rational::operator *= (const Rational& r)
{
  mNumerator *= r.mNumerator;
  mDenominator *= r.mDenominator;
  reduce();
  return *this;
}

Rational& Rational::operator /= (const Rational& r)
{
  if( r.mNumerator == 0 )
  {
    cerr << "ERROR: division by zero" << endl;
  }
  mNumerator *= r.mDenominator;
  mDenominator *= r.mNumerator;
  reduce();
  return *this;
}

istream& operator >> (istream& in, Rational& r)
{
  int num, den;
  in >> num >> den;
  r.setRational(num, den);
  return in;

}

ostream& operator << (ostream& out, const Rational& r)
{
  out << r.mNumerator << '/' << r.mDenominator;
  return out;
}

//--Prywatne-----

int Rational::NWD(int a, int b)
{
  a = abs(a);
  b = abs(b);

  while(b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

void Rational::reduce()
{
  int nwd = NWD( mNumerator, mDenominator );
  mNumerator /= nwd;
  mDenominator /= nwd;

  if( mDenominator < 0 )
  {
    mNumerator*=(-1);
    mDenominator*=(-1);
  }
}
