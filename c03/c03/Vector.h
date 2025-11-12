#pragma once
#include <iostream>
using namespace std;

#define VEC_ALLOCATION_ERROR   0x80
#define VEC_SIZE_ERROR         0x01
#define VEC_INDEX_ERROR        0x02
#define VEC_INCOMPATIBLE_ERROR 0x03
#define VEC_OTHER_ERROR        0xFF

typedef unsigned short USHORT;

class VecException 
{
public:
  VecException( USHORT errCode = VEC_OTHER_ERROR  ) { mErrCode = errCode; }
  const char* getReason();
private:
  USHORT mErrCode;
};

inline const char* VecException::getReason() {
switch( mErrCode )
{
case VEC_ALLOCATION_ERROR: return "ERROR: memory allocation error!\n";
case VEC_SIZE_ERROR: return "ERROR: invalid vector size!\n";
case VEC_INDEX_ERROR: return "ERROR: index out of range!\n";
case VEC_INCOMPATIBLE_ERROR: "ERROR: incompatible vector sizes!\n";
default: return "ERROR: other error!\n";
}
}


class Vector
{
public:
  explicit Vector( int nSize=2, int nElem=0 );
  Vector( const Vector& v ); // konstruktor kopiujacy
  virtual ~Vector(); // destruktor

  //---------getter------------
  int getDim() const;

  //---------assignment---------------------------------------
  Vector& operator =( const Vector& v ); // v1 = v

  //---------input/output
  friend istream& operator >> ( istream& in, Vector& v );
  friend ostream& operator << ( ostream& out, const Vector& v );

  //---------addition-------------------
// v1 + v2 <-- niezalezne od argumentu, wiec funkcja jest globalna
  friend const Vector operator + ( const Vector& v1, const Vector& v2 );


// v + 4, 4 + v <-- tj. zaprzyjazniona z klasa
  friend const Vector operator + ( const Vector& v1, double x );
  friend const Vector operator + ( double x, const Vector& v1 );

// v1 += v <-- v1.operator +=( v ) modyfikuje aktualny obiekt = metoda klasy
  Vector& operator +=( const Vector& v );
// v1 += 4 <-- v1.operator +=( 4 )
  Vector& operator +=( double x );

  // substraction
  friend const Vector operator - ( const Vector& v1, const Vector& v2 );
  friend const Vector operator - ( const Vector& v1, double x );
  Vector& operator -=( const Vector& v );
  Vector& operator -=( double x );

  // unary minus
  friend const Vector operator - (const Vector& v ); //-v

  // multiplication
  friend const Vector operator * ( const Vector& v, double x );
  friend const Vector operator * ( double x, const Vector& v );
  Vector& operator *= (double x);

  // scalar multiplication
  friend double operator * ( const Vector& v1, const Vector& v2 );

  // comparision
  friend bool operator == ( const Vector& v1, const Vector& v2 );
  friend bool operator != ( const Vector& v1, const Vector& v2 );

  // index
  double& operator [] ( int ix );
  const double& operator[]( int ix ) const;

  // konwersja do doubke
  explicit operator double*() const { return m_pCoord; }


private:
  void createVec( int nSize );
  void copyVec( const Vector& v );

private:
  double* m_pCoord; // wspolrzedne wektora dynamicznego
  int mDim;
};

//------------ INLINE FUNCTIONS ------------------------
inline int Vector::getDim() const {
  return mDim;
}

inline void Vector::createVec( int nSize ) {
  if( nSize < 2)
  {
    nSize = 2;
    /*cerr << "ERROR: invalid vector size!\n";*/
    throw VecException(VEC_SIZE_ERROR);
  }

  mDim = nSize;
  m_pCoord = new(nothrow) double[mDim]; //! WA¯NE w przypadku bledu zwroci NULL lub nullptr
}

inline void Vector::copyVec( const Vector& v ) {
  // memcpy( this->m_pCoord, v.m_pCoord, getDim()*sizeof( double ) );
  memcpy( this->m_pCoord, (double*)v, getDim()*sizeof( double ) );

}


/*
zdefiniowac skladowe prywatne, reprezentujace obiekt tej klasy
konstrukcja obiektu:
            - z parametrami domyslnymi
            - kopiujacy
destruktor (najczesciej jesli  mamy skladowe dynamiczne)

settery/gettery
operatory:
  - podstawienia (powinien byc gdy skladowa dynamiczna)
  - wejscia/wyjacia
  - pozostale operatory ( o ile trzeba )

  Pozostale metody publiczne i prywatne (jako pomocnicze do realizacji metod publicznych)

*/