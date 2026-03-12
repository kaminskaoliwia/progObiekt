
#include <iostream>
using namespace std;
#include "Vector.h"
#include "Matrix.h"

//#define TEST_VECTOR
#define TEST_MATRIX
int main()
{

#ifdef TEST_MATRIX
  Matrix m1;
  cout << "m1 = " << m1 << endl;

  Matrix m2(2,3,3);
  cout << "m2 = " << m2 << endl;

  m1 = m2;
  cout << "m1 po postawieniu = " << m2 << endl;

  Matrix m3(3,2,5);
  cout << "m3 = " << m3 << endl;

  m3 *= 2;
  cout << "m3 po pomnozeniu przez 2 = " << m3 << endl;

  Matrix m4( 2,2 );
  m4 = m2 * m3;
  cout << "m4 = m2 * m3" << m4 << endl;

  Vector v0(2,2);
  cout << "v0 = " << v0 << endl;
  v0 = m4*v0;
  cout << "v0 = m4 * v0 " << v0 << endl;
  
  Matrix m5( m4 );
  cout << "konstruktor kopiujacy\n" << m5;
#endif

#ifdef TEST_VECTOR

  Vector v1;
  cout << "v1 = " << v1 << endl;

  Vector v2( 3, 2 );
  cout << "v2 = " << v2 << endl;

  v1 = v2; // operator podstawienia
  cout << "v1 po podstawieniu = " << v1 << endl;

  Vector v3( 5, -1 );
  Vector v4( v3 ); // Vector v4 = v3 -- TO SAMO
  cout << "v4  po kopiowaniu = " << v4 << endl;

  v4 = v4 + 3;
  cout << "v4 po dodaniu liczby = " << v4 << endl;

  v1 = v3 + v4;
  cout << "v4 po dodaniu wektora = " << v1 << endl;

  cout << "Podaj wsp wektora o rozmiarze " << v1.getDim() << " : ";
  cin >> v1;
  cout << "v1 = " << v1 << endl;

  v1 = v1*2;
  cout << "v1*2 = " << v1 << endl;

  cout << "v1*v3 = " << v1*v3 << endl;
  
  try 
  {
    v1[1] = -35;
    v1[-2] = v1[1] + 10;
  }
  catch( VecException e )
  {
    cerr << e.getReason() << endl;
  }
  cout << "v1 = " << v1 << endl;

#endif


  

  return 0;
}


