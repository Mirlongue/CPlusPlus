#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;

struct Data{
    int x = 0;
};

class IntWrapper {
public:
    Data  value;
    int tmp;
    IntWrapper(Data  p, int tmp =0): value(p),tmp(tmp) {}
    Data * operator->() { return  &value;}
};


class SmartPtr {
    Data* ptr;
    int tmp;
public:
    // 返回原生指针，直接访问成员
    SmartPtr(Data * p, int tmp = 0) : ptr(p),tmp(tmp){}
    Data* operator->() { return ptr; } 
};


int main() {
    Data y;
    IntWrapper demo(y, 5);
    cout << demo->x << endl;
    

    SmartPtr sp(new Data);
    sp->x = 10; // 等价于 (sp.operator->())->x
    cout << sp->x << endl;
    return 0;
}