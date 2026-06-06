#include <cstdio>
#include "sub.h"

using namespace std;

namespace{
int foo(int a) {
  puts("I am foo\n");
  return 0;
}

int printf_stub(const char *format, ...) {
  cout << "I am printf_stub" << endl;
  return 0;
}

}

namespace sub {
int cas_12() {
  Stub stub;
  stub.set(puts, printf_stub);
  foo(1);
  return 0;
}
}