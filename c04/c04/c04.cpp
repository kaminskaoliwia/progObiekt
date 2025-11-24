#include <iostream>
using namespace std;

#include "Stack.h"

int main()
{
  // konkretyzacja T
  Stack<char> cS;
  Stack<double> dS;

  try
  {
    char c = cS.top();
  }
  catch( StackException e)
  {
    cout << endl << "*** " << e.getReason() << "***" << endl << endl;
  }

    /* Stack<char> cS1; // nie ma konkretyzacji bo juz byla dla typu char */
  
  dS.push( 1 );
  dS.push( 2 );
  dS.push( 3 );

  cS.push( 'A' );
  cS.push( 'B' );
  cS.push( 'C' );

  cout << endl;

  cout << dS.pop() << ' ';
  cout << dS.pop() << ' ';
  cout << dS.pop() << endl;

  try 
  {
  if(cS.pop() == 'C') 
    if (cS.pop() == 'B')
      if (cS.pop() == 'A')
      {
        cout << "Char stack operations: OK !!!" << endl;
      }
  }
  catch( StackException& e )
  {
      cout << endl << "*** " << e.getReason() << "***" << endl << endl;
  }
;
  /*
  * 
  StackItem* p = new StackItem('a', NULL)
  
  try {
    
    Stack s1;
    s1.push( 'A' );
    s1.push( 'B' );
    s1.push( 'C' );

    // cout << s1.pop() << ' ' << s1.pop() << ' ' << s1.pop(); = tak nie mozna bo moze dzialac dobrze lub zle
    cout << s1.pop() << ' ';
    cout << s1.pop() << ' ';
    cout << s1.pop();

    cout << endl;

    Stack s2;
    s2.push( '1' );
    s2.push( '2' );

    cout << s2.pop();
    cout << endl;
  }

  catch( StackException& e)
  {
    cerr << e.getReason() << endl;
  }
  */
  return 0;
}





/*
NOTATKI:
lepiej sie zaprzyjazniac niz zagniezdzac (definiowanie klasy w klasie)
this raczej jest opcjonalny, ale sa przypadki (np. lista z wskaznikiem na prev i na next, this wskazuje na biezacy element) kiedy sa wymagane 

class X
{
struct M1 (int m ); //private
public: 
struct M2 ( int m )

void f()
{
M1 a; // error 
M1 b; // error bo nie moze sie dostac do M1
X::M1 c; // error bo prywatna
X::M1 dl // ok
}

X::M1 X::f(X::M2) - niedokonczone

skladowe statyczna - skladowa wspolna dla kazdego obiektu danej klasy

wskaŸniki do sk³adowych .* ->* 
raczej da sie tego nigdy nie uzyc
int X::*z = &X::a // wskaznik do skladowej klasy, nawet jezeli nie ma obiektu
obiekt.*z = 4 == obiekt.a = 4

dynamic cast = umoznliwia sprawdzanie typow podczas dzialania programu
rzutowanie wskaznikow i regerencji
zeby uzyc trzeba miec co najmniej jedna klase wirtualna

reinterpret cast

JAVA = brak kontrali nad pamiêci¹


*/

