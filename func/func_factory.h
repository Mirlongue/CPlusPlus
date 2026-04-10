#ifndef FUNC_FACTORY_H
#define FUNC_FACTORY_H

#include <string>
#include <memory>
#include "func_base.h"
namespace func {

using allocter = std::shared_ptr<Base> (*)(int, int);

struct Factory {

Factory() = default;
~Factory() = default;

static Factory & GetInstance();

void Create();
void Register();

};

struct Register {
    Register(std::string);
    ~Register()= default;
};



} // namespace func

#endif // FUNC_FACTORY_H