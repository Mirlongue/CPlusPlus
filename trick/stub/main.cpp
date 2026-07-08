#include <iostream>
#include <string>
#include "stub.h"

using namespace std;

template <typename PtrType, PtrType PtrValue, typename TagType>
struct private_access {
    friend PtrType get(TagType) { return PtrValue; }
};

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

struct PrivateAccessTag__COUNTER__ {};
template struct private_access<decltype(&A::x_), &A::x_,
        PrivateAccessTag__COUNTER__>;

int A::* get(PrivateAccessTag__COUNTER__);


#define PRIVATE_ACCESS_DETAIL_CONCATENATE_IMPL(x, y) x##y
#define PRIVATE_ACCESS_DETAIL_CONCATENATE(x, y)                                \
  PRIVATE_ACCESS_DETAIL_CONCATENATE_IMPL(x, y)

int main() {

    A a;
    a.setX(4);
    cout << a.getX() << endl;

    int & A_x = a.*get(PrivateAccessTag__COUNTER__{});
    A_x = 5;
    cout << a.getX() << endl;

    int PRIVATE_ACCESS_DETAIL_CONCATENATE(PrivateAccessTag, __COUNTER__) = 666;

    cout <<  PrivateAccessTag0 << endl;

    int PRIVATE_ACCESS_DETAIL_CONCATENATE(PrivateAccessTag, __COUNTER__) = 777;

    cout <<  PrivateAccessTag1 << endl;

    return 0;
}