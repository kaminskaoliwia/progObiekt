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
  int num;
  int denum;

  if( r1.mDenominator == r2.mDenominator )
  {
    num = r1.mNumerator + r2.mNumerator;
    denum = r1.mDenominator;
  }
  else
  {
    num = r1.mNumerator * r2.mDenominator + r2.mNumerator * r1.mDenominator;
    denum = r1.mDenominator * r2.mDenominator;
  }

  return Rational(num, denum);
}

const Rational operator - (const Rational& r1, const Rational& r2)
{
  return r1 + Rational(-r2.mNumerator, r2.mDenominator);
}

const Rational operator * (const Rational& r1, const Rational& r2)
{
  return Rational(r1.mNumerator*r2.mNumerator, r1.mDenominator*r2.mDenominator);
}

const Rational operator / (const Rational& r1, const Rational& r2)
{
  return r1 * Rational(r2.mDenominator, r2.mNumerator); // dzielenie = mnozenie przez odwrotnosc
}

Rational& Rational::operator += (const Rational& r)
{
  *this = *this + r;
  return *this;
}

Rational& Rational::operator -= (const Rational& r)
{
  *this = *this - r;
  return *this;
}

Rational& Rational::operator *= (const Rational& r)
{
  *this = *this * r;
  return *this;
}

Rational& Rational::operator /= (const Rational& r)
{
  *this = *this / r;
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
