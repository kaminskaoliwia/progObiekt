#include <iostream>
#include "Segm.h"
using namespace std;

int main() {
  Segm sg1(0,0,1,1);
  Segm sg2( Point(1,0), Point(0,1));

  int angle = 45;
  cout << "Obrot odcinka sgl: " << sg1 << "o kat " << angle << endl;
  sg1.Rotate(angle);
  cout << "sg1 po obrocie = " << sg1 << endl;
  cout << "Dlugosc sg1 = " << sg1.segmLen() << endl;

  cout << "Obrot odcinka sgl: " << sg2 << "o kat " << angle << endl;
  sg2.Rotate(angle);
  cout << "sg1 po obrocie = " << sg2 << endl;
  cout << "Dlugosc sg2 = " << sg2.segmLen() << endl;

  return 0;
}