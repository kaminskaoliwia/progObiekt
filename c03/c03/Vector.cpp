#include "Vector.h"

Vector::Vector( int nSize/*=2*/, int nElem/*=0*/ ) {
  createVec( nSize ); // funkcja prywatna
  if( !m_pCoord )
    throw VecException(VEC_ALLOCATION_ERROR);

  for( int i=0; i<getDim(); i++ )
    m_pCoord[i] = nElem;
}

Vector::Vector( const Vector& v ) {
  mDim = 0;
  m_pCoord = nullptr; // albo NULL
  *this = v;
}

Vector::~Vector() {
  delete [] m_pCoord;
}

Vector& Vector::operator =( const Vector& v ) {
  if(this->getDim() != v.getDim() )
  {
    delete [] m_pCoord;
    createVec( v.getDim() );
  }

  copyVec( v );
  return *this;
}

istream& operator >> ( istream& in, Vector& v ) {
  
  for( int i=0; i<v.getDim(); i++ )
    in >> v.m_pCoord[i];

  return in;
}

ostream& operator << ( ostream& out, const Vector& v ) {

   out << '[';
   for( int i=0; i<v.getDim(); i++ )
   {
     out<< v.m_pCoord[i];
    if( i<v.getDim()-1 )
      out << ',';
   }
   out << ']';
  return out;
}

//----------------------------------------------------------------------------------
const Vector operator +( const Vector& v1, const Vector& v2 ) {
  Vector res( v1 );
  return res += v2;
}

const Vector operator +( const Vector& v1, double x ) {
  Vector res( v1 );
  return res += x;
}

const Vector operator +( double x, const Vector& v1 ) {
  return v1 + x;
}

Vector& Vector::operator +=( const Vector& v ) {
  if( this->getDim() != v.getDim() )
  {
    /*cerr << "ERROR: incompatible vector sizes!\n";
    return *this;*/
    throw VecException(VEC_INCOMPATIBLE_ERROR);
  }
  for( int i=0;i<this->getDim(); i++ )
    this->m_pCoord[i] += v.m_pCoord[i];

  return *this;
}

Vector& Vector::operator +=( double x ) {
  for( int i=0; i<this->getDim(); i++ )
    m_pCoord[i] += x;
  return *this;
}

const Vector operator - ( const Vector& v1, const Vector& v2 ) {
  /*Vector res( v1 );
  return res -= v2;*/
  return v1 + (-v2);
}

const Vector operator - ( const Vector& v1, double x ) {
  /*Vector res( v1 );
  return res -= x;*/
  return v1 + (-x);
}


Vector& Vector::operator -=( const Vector& v ) {
  /*if( this->getDim() != v.getDim() )
  {
    cerr << "ERROR: incompatible vector sizes!\n";
    return *this;
  }
  for( int i=0;i<this->getDim(); i++ )
    this->m_pCoord[i] -= v.m_pCoord[i];

  return *this;*/
  return *this += (-v);
}

Vector& Vector::operator -=( double x ) {
  /*for( int i=0; i<this->getDim(); i++ )
    m_pCoord[i] -= x;
  return *this;*/
  return *this += -x;

}

const Vector operator- (const Vector& v ) {
  Vector res( v );
  for(int i=0; i<v.getDim();i++ )
    res.m_pCoord[i] = -res.m_pCoord[i];
  return res;
}

// multiplication
const Vector operator * ( const Vector& v, double x ) {
  
  Vector res( v );
  return res *= x;

}

const Vector operator * ( double x, const Vector& v ) {
  return v*x;
}

Vector& Vector::operator *= (double x) {
  for( int i = 0; i < this->getDim(); i++ )
  {
    m_pCoord[i]*=x;
  }

  return *this;
}

// scalar multiplication
double operator * ( const Vector& v1, const Vector& v2 ) {

    if (v1.getDim() != v2.getDim()) {
      /*cerr << "ERROR: incompatible vector sizes!\n";
      return 0;*/
      throw VecException(VEC_INCOMPATIBLE_ERROR);
    }

    double result = 0.0;
    for (int i = 0; i < v1.getDim(); i++)
      result += v1.m_pCoord[i] * v2.m_pCoord[i];
    return result;
}

// comparision
bool operator == ( const Vector& v1, const Vector& v2 ) {
  if( v1.getDim() != v2.getDim() )
  {
    return false;
  }

  for(int i=0; i < v1.getDim(); i++ )
    if( v1.m_pCoord[i] != v2.m_pCoord[i] ) return false;

  return true;
}
bool operator != ( const Vector& v1, const Vector& v2 ) {
  return !(v1 == v2);
}

double& Vector::operator [] ( int ix )
{
  if( ix < 0 || ix >= getDim() )
  { /*
    cerr << "ERROR: index out of range !!\n";
    return m_pCoord[0]; */
    throw VecException(VEC_INDEX_ERROR);
  }
  return m_pCoord[ix];
}

const double& Vector::operator [] ( int ix ) const {
if( ix < 0 || ix >= getDim() )
{
  /* cerr << "ERROR: index out of range !!\n";
  return m_pCoord[0]; */
  throw VecException(VEC_INDEX_ERROR);
}
return m_pCoord[ix];
}