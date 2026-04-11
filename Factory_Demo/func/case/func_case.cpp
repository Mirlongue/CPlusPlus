#include "func_case.h"
namespace func {

Case::Case(int a, int b):Base(a), b_(b) {}

int Case::Plus(int x, int y) {
    return x + y + a_ + b_;
}


}