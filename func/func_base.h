#ifndef FUNC_BASE_H
#define FUNC_BASE_H

namespace func {
struct Base {

Base(int);
~Base() = default;

virtual int Plus(int, int);

int a_ = 0;
};

} // namespace func



#endif // FUNC_BASE_H
