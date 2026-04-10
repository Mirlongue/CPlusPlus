#include <memory>
#include <iostream>
#include "func_base.h"
#include "func_case.h"
using namespace std;
using namespace func;
int main() {
    shared_ptr<Base> ptr;
    ptr = make_shared<Base>(5);
    cout << ptr->Plus(1,2) << endl;
    ptr = make_shared<Case>(5, 5);
    cout << ptr->Plus(1,2) << endl;
    return 0;
}