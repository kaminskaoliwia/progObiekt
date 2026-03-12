#include "Matrix.h"

Matrix::Matrix(int nRows, int nCols, double nElem) {
  
  if( nRows < 2 || nCols < 2 )
    throw MatException( MAT_SIZE_ERROR );
  
  this->nRows = nRows;
  this->n_mRows = new Vector[nRows];

  for (int i = 0; i < nRows; i++) {
    this->n_mRows[i] = Vector(nCols, nElem);
  }
}

Matrix::Matrix(const Matrix& m) {
  /*nRows = m.nRows;
  n_mRows = new Vector[nRows];

  for (int i = 0; i < nRows; i++) {
    n_mRows[i] = m.n_mRows[i];
  }*/

  //zainicjowac
  n_mRows = nullptr;
  nRows = 0;
  *this = m;
}

Matrix::~Matrix() {
}

istream& operator >> ( istream& in, Matrix& m ) 
{
  for( int i=0; i<m.getRows(); i++ ) {
    in >> m.n_mRows[i];
  }
  return in;
}

ostream& operator << ( ostream& out, const Matrix& m ) {
  out << '\n';
  out << '[';
  for( int i=0; i<m.getRows(); i++ )
  {
    out << m.n_mRows[i];
    if( i < m.getRows() - 1 ) {
      out << ',';
      out << '\n'; }
  }
  out << ']';
  out << '\n';
  return out;
}

const bool operator == ( const Matrix& m1, const Matrix& m2 ) 
{
  for(int i=0; i<m1.getRows(); i++) {
    if( m1.n_mRows[i] != m2.n_mRows[i] )
      return false;
  }
  return true;
}


Matrix& Matrix::operator = ( const Matrix& m )
{
  if( (getRows() != m.getRows()) || (getCols() != m.getCols()) ) 
  {
    delete[] n_mRows;
    nRows = m.getRows();
    createMatrix( m.getRows(), m.getCols() );
  }
  copyMatrix( m );
  return *this;
}

const bool operator != ( const Matrix& m1, const Matrix& m2 ) 
{
  return !(m1 == m2);
}

const Matrix operator * (const Matrix& m, int x)
{
  Matrix res( m );
  return res *= x;
}

const Matrix operator * (int x, const Matrix& m) 
{
  return m * x;
}

Matrix& Matrix::operator *= ( int x ) {
  for(int i=0; i<this->getRows(); i++) {
    this->n_mRows[i] *= x;
  }
  return *this;
}

//const Vector operator * ( const Vector& v, const Matrix& m )
//{
//  if( v.getDim() != m.getRows() ) {
//    throw MatException(MAT_INCOMPATIBLE_ERROR);
//  }
//  Vector res(m.getCols(), 0);
//  for( int j=0; j<m.getCols(); j++ ) {
//    for( int i=0; i<m.getRows(); i++ ) {
//      res[j] += v[i] * m.n_mRows[i][j];
//    }
//  }
//  return res;
//}

const Vector operator * ( const Matrix& m, const Vector& v )
{
  if( v.getDim() != m.getCols() ) {
    throw MatException(MAT_INCOMPATIBLE_ERROR);
  }
  Vector res(m.getRows(), 0);
  for( int i=0; i<m.getRows(); i++ ) {
          res[i] = v * m.n_mRows[i];
  }
  return res;
}

const Matrix operator * ( const Matrix& m1, const Matrix& m2 )
{
  if( m1.getCols() != m2.getRows() ) {
    throw MatException(MAT_INCOMPATIBLE_ERROR);
  }

  Matrix res(m1.getRows(), m2.getCols(), 0);

  for(int i = 0; i < m1.getRows(); ++i) {
    for(int k = 0; k < m1.getCols(); ++k) {
      for(int j = 0; j < m2.getCols(); ++j) {
        res.n_mRows[i][j] += m1.n_mRows[i][k] * m2.n_mRows[k][j];
      }
    }
  }
  return res;
}
