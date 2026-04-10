#include "func_factory.h"
namespace func {

Factory & Factory::GetInstance() {
    static Factory ins;
    return ins;
}

void Factory::Create() {

}

void Factory::Register() {
    
}



Register::Register(std::string st) {
    Factory::GetInstance().Register();
}

#define REGISTER()           \


}