#include <memory>
#include <iostream>
#include "func_base.h"
#include "func_case.h"
#include "func_factory.h"
using namespace std;
using namespace func;


REGISTER("Case",Case)

int main() {
    shared_ptr<Base> ptr;
    ptr = Factory::GetInstance().Create("Case", 5, 5);

    cout << ptr->Base::Plus(1, 1) << endl;
    cout << ptr->Plus(1, 1) << endl;

    return 0;
}