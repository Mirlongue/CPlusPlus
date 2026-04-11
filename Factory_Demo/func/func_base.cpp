#include "func_base.h"
namespace func {

Base::Base(int a):a_(a) {}

int Base::Plus(int x, int y) {
    return x + y + a_;
}


}