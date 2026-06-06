#include "sub.h"

using namespace std;

namespace{
class A {
  int a;
  int foo(int x) {
    cout << "I am A_foo " << a << endl;
    return 0;
  }
  static int b;
  static int bar(int x) {
    cout << "I am A_bar " << b << endl;
    return 0;
  }
};

int A::b = 10;

int foo_stub(void *obj, int x) {
  A *o = (A *)obj;
  cout << "I am foo_stub" << endl;
  return 0;
}
int bar_stub(int x) {
  cout << "I am bar_stub" << endl;
  return 0;
}


}

namespace sub {


int cas_9() {
  A a;
  a.a = 1;

  a.foo(0);
  A::bar(0);

  Stub stub;
  stub.set(ADDR(A, foo), foo_stub);
  stub.set(ADDR(A, bar), bar_stub);

  a.foo(0);
  A::bar(0);

  return 0;
}



}