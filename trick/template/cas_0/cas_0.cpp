#include <iostream>
#include "cas_0.h"

using namespace std;

namespace cas {

typedef int Tp; // int double float


void cas_0() {
    Tp x(1);
    Tp y(2);
    cout << x << " " << y << endl;
    Swap(x,y);
    cout << x << " " << y << endl;

    stack<int> z;
    Tset(z);

}

}