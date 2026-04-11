#ifndef FUNC_CASE_H
#define FUNC_CASE_H

#include "func_base.h"
namespace func {
struct Case : public Base {

Case(int, int);
~Case() = default;

virtual int Plus(int, int);

int b_ = 0;
};

} // namespace func



#endif // FUNC_Case_H