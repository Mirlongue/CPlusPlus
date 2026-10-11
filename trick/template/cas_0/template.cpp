#include <iostream>
#include "cas_0.h"

using namespace std;

namespace cas {
template <typename T>
void Swap(T &a, T &b) {
    T c = a; a = b; b = c;
    std::cout << "template" << std::endl;
}

// explicit specialization
template <> void Swap<int>(int & a, int & b) {
    int c = a; a = b; b = c;
    std::cout << "int" << std::endl;

}

// explicit instantiation
template void Swap<double>(double &, double &);
// template void Swap<float>(float &, float &);

}