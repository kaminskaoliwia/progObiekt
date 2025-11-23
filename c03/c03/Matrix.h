#pragma once
#include <iostream>
using namespace std;
#include "Vector.h"

class Matrix
{
public:
  explicit Matrix( int nRows = 3, int nCols = 3, int nElem = 0);
  Matrix( const Matrix& m ); // konstruktor kopiujacy
  virtual ~Matrix(); // destruktor

  //----gettery-----
  inline int getCols() const;
  inline int getRows() const;

  //----input/output----
  friend istream& operator >> ( istream& in, Matrix& m );
  friend ostream& operator << ( ostream& out, const Matrix& m );

  //----index---
  Vector& operator [] ( int ix );
  const Vector& operator [] ( int ix ) const;

  //----operations---- const bool = stala wartosc logiczna true/false
  friend const bool operator == ( const Matrix& m1, const Matrix& m2 ); // porownanie
  friend const bool operator != ( const Matrix& m1, const Matrix& m2 );

  friend const Matrix operator * (const Matrix& m, int x); // macierz * x
  friend const Matrix operator * (int x, const Matrix& m); // x * macierz
  Matrix& operator *= ( int x );

  friend const Vector operator * ( const Vector& v, const Matrix& m ); // wektor * macierz

  friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 ); // mno¿enie macierzy

private:
  int nRows; //! liczba wierszy macierzy
  Vector* n_mRows; //! tablica wektorow reprezentujacych wiersze macierzy
  //! nie ma kolumn jako osobnej struktury, poniewa¿ kolumny to po prostu iloœæ elementów w wektorach
};

//----INLINE----
inline int Matrix::getRows() const {
  return this->nRows;
}

inline int Matrix::getCols() const {
  return this->n_mRows->getDim();
}