#ifndef FUNC_FACTORY_H
#define FUNC_FACTORY_H

#include <string>
#include <memory>
#include <map>
#include "func_base.h"
namespace func {

using Allocater = std::shared_ptr<Base> (*)(int, int);

struct Factory {

Factory() = default;
~Factory();

static Factory & GetInstance();

std::shared_ptr<Base> Create(std::string, int, int);

void Register(std::string, Allocater);

std::map<std::string, Allocater> funcMap;

};

struct Register {

    Register(std::string, Allocater);
    ~Register()= default;
};

#define REGISTER(name, type)                             \
shared_ptr<Base> gen##type##Allocater(int a, int b) {    \
    return make_shared<type>(a,b);                       \
}                                                        \
Register gen##type##Register(name, genCaseAllocater);    \


} // namespace func

#endif // FUNC_FACTORY_H