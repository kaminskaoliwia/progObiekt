#pragma once
#include <iostream>
using namespace std;
#include "Vector.h"

#define MAT_ALLOCATION_ERROR   0x81
#define MAT_SIZE_ERROR         0x11
#define MAT_INDEX_ERROR        0x12
#define MAT_INCOMPATIBLE_ERROR 0x13
#define MAT_OTHER_ERROR        0xAF

typedef unsigned short USHORT;

class MatException 
{
public:
  MatException( USHORT errCode = MAT_OTHER_ERROR  ) { mErrCode = errCode; }
  const char* getReason();
private:
  USHORT mErrCode;
};

inline const char* MatException::getReason() {
  switch( mErrCode )
  {
  case MAT_ALLOCATION_ERROR: return "ERROR: memory allocation error!\n";
  case MAT_SIZE_ERROR: return "ERROR: invalid matrix size!\n";
  case MAT_INDEX_ERROR: return "ERROR: index out of range!\n";
  case MAT_INCOMPATIBLE_ERROR: "ERROR: incompatible matrix sizes!\n";
  default: return "ERROR: other error!\n";
  }
}

class Matrix
{
public:
  explicit Matrix( int nRows = 3, int nCols = 3, double nElem = 0);
  Matrix( const Matrix& m ); // konstruktor kopiujacy
  virtual ~Matrix(); // destruktor

  //----gettery-----
  inline int getCols() const;
  inline int getRows() const;

  //----input/output----
  friend istream& operator >> ( istream& in, Matrix& m );
  friend ostream& operator << ( ostream& out, const Matrix& m );
  Matrix& operator = ( const Matrix& m ); // podstawienie

  //----index---
  const Vector& operator [] ( int ix );
  const Vector& operator [] ( int ix ) const;

  //----operations---- const bool = stala wartosc logiczna true/false
  friend const bool operator == ( const Matrix& m1, const Matrix& m2 ); // porownanie
  friend const bool operator != ( const Matrix& m1, const Matrix& m2 );

  friend const Matrix operator * (const Matrix& m, int x); // macierz * x
  friend const Matrix operator * (int x, const Matrix& m); // x * macierz
  Matrix& operator *= ( int x );

 // friend const Vector operator * ( const Vector& v, const Matrix& m ); // wektor * macierz
  friend const Vector operator * ( const Matrix& m, const Vector& v ); //  macierz * wektor
  friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 ); // mno¿enie macierzy

private:
  int nRows; //! liczba wierszy macierzy
  Vector* n_mRows; //! tablica wektorow reprezentujacych wiersze macierzy
  //! nie ma kolumn jako osobnej struktury, poniewa¿ kolumny to po prostu iloœæ elementów w wektorach

private:
  inline void copyMatrix( const Matrix& m );
  inline void createMatrix( int nRows, int nCols );
};

//----INLINE----
inline int Matrix::getRows() const {
  return this->nRows;
}

inline int Matrix::getCols() const {
  return this->n_mRows->getDim();
}

inline void Matrix::copyMatrix( const Matrix& m )
{
  for( int i = 0; i < m.getRows(); i++ )
    this->n_mRows[i] = m.n_mRows[i];
}

inline void Matrix::createMatrix( int nRows, int nCols )
{
  if( nRows < 2 || nCols < 2 )
    throw MatException( MAT_INCOMPATIBLE_ERROR );
  
  n_mRows = new Vector[nRows];
}

inline const Vector& Matrix::operator[]( int ix ) const 
{
  if( ix < 0 || ix >= getRows() ) 
  {
    throw MatException( MAT_SIZE_ERROR );
    return n_mRows[0];
  }
  return n_mRows[ix];
}

inline const Vector& Matrix::operator[]( int ix ) 
{
  if( ix < 0 || ix >= getRows() ) 
  {
    throw MatException( MAT_SIZE_ERROR );
    return n_mRows[0];
  }
  return n_mRows[ix];
}