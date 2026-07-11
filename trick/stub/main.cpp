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
    friend int A::* fgetX(A) {
        return &A::x_;
    }
};

ACCESS_PRIVATE_FIELD(A, int, x_);
// namespace {
//     struct PrivateAccessTag6 {};
//     template struct private_access<decltype(&A::x_), &A::x_, PrivateAccessTag6>;
//     using Alias_PrivateAccessTag6 = int;
//     using PtrType_PrivateAccessTag6 = Alias_PrivateAccessTag6 A::*;
//     PtrType_PrivateAccessTag6 get(PrivateAccessTag6);
// }
// namespace {
//     int & Ax_(A &&t) { return t.*get(PrivateAccessTag6{}); }
//     int & Ax_(A &t) { return t.*get(PrivateAccessTag6{}); }
//     using XPrivateAccessTag6 = int;
//     using YPrivateAccessTag6 = const XPrivateAccessTag6;
//     YPrivateAccessTag6 & Ax_(const A &t) { return t.*get(PrivateAccessTag6{}); }
// }

int main() {

    A a;

    a.setX(0);
    cout << a.getX() << endl;

    int & A_x = Ax_(a);
    A_x = 1;
    cout << a.getX() << endl;

    A_x = 2;
    cout << a.*fgetX(a) << endl;

    return 0;
}