
#include <iostream>
using namespace std;
#include "Vector.h"

// #define TEST_VECTOR

int main()
{
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


