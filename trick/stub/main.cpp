#include <iostream>
#include <string>
#include "stub.h"

using namespace std;

struct A {
private:
    int x_;

public:
    void setX(int x) {
        x_ = x;
    }
    int getX() {
        return x_;
    }
};

// template <typename PtrType, PtrType PtrValue, typename TagType>
// struct private_access {
//     friend PtrType get(TagType) { return PtrValue; }
// };

// struct PrivateAccessTag__COUNTER__ {};
// template struct private_access<decltype(&A::x_), &A::x_,
//         PrivateAccessTag__COUNTER__>;

// int A::* get(PrivateAccessTag__COUNTER__);

ACCESS_PRIVATE_FIELD(A, int, x_);

int main() {

    A a;
    a.setX(4);
    cout << a.getX() << endl;

    // int & A_x = a.*get(PrivateAccessTag__COUNTER__{});

    int & A_x = Ax_(a);

    A_x = 5;
    cout << a.getX() << endl;

    return 0;
}