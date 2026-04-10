#include "func_factory.h"
namespace func {

Factory::~Factory() {
    funcMap.clear();
}

Factory & Factory::GetInstance() {
    static Factory ins;
    return ins;
}

std::shared_ptr<Base> Factory::Create(std::string name, int a, int b) {

    std::map<std::string, Allocater>::iterator it = funcMap.find(name);
    if(it == funcMap.end()) {
        return nullptr;
    }
    return (it->second)(a, b);
}

void Factory::Register(std::string name, Allocater allocater) {
    std::map<std::string, Allocater>::iterator it = funcMap.find(name);
    if(it == funcMap.end()) {
        funcMap[name] = allocater;
    }
    return;
}



Register::Register(std::string name, Allocater allocater) {
    Factory::GetInstance().Register(name, allocater);
}




}