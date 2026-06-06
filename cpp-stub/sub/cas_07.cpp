#include "sub.h"

using namespace std;

namespace {

class A {
public:
  virtual int foo(int a) {
    cout << "I am A_foo" << endl;
    return 0;
  }
};

int foo_stub(void *obj, int a) {
  A *o = (A *)obj;
  cout << "I am foo_stub" << endl;
  return 0;
}

}

namespace sub {

int cas_7() {
  typedef int (*fptr)(A *, int);

  using virtual_function_type = int (*)(A *, int);

  virtual_function_type A_foo =
      (virtual_function_type)(&A::foo);
  Stub stub;
  stub.set(A_foo, foo_stub);
  A a;
  a.foo(1);
  return 0;
}

}