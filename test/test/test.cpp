#include <iostream>
#include "testDll.h"
#include "Date.h"
#include "CTime.h"
#include "DateTime.h"
using namespace std;

int main()
{
    Date d(15, 1, 2026);
    cout << "d = " << d << endl;

    Time t(22, 10, 24);
    cout << "t = " << t << endl;

    DateTime dt(d, t);
    cout << "Dt = " << dt << endl;

    return 0;
}
