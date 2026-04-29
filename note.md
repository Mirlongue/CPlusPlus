## const

global variables, internal linking, make it externally linked via `extern`

## static

local variables, in static storage area, initialize once

global variables, change the link to internal

member variables, variables belong to the class itself

member functions, functions belong to the class itself

## typedef

alias

simplify complex types

​	starting from the variable name, proceed from right to left

## using

introduction

alias

inherited constructor (using BaseClass::BaseClass)

## #define

stringification:		#

mark connection:	  ##

## template

```c++
template <typename T>
void Swap(T &a, T &b) {
    T c = a; a = b; b = c;
}

// explicit concretion
template <> void Swap<int>(int &, int &) {
    int c = a; a = b; b = c;
}

template <> void Swap(int &, int &) {
    int c = a; a = b; b = c;
}

// explicit instantiation
template void Swap<int>(int, int);
```


```c++
template <typename T>
struct Iter {
    typedef T value_type;
    Iter(T x) : x_(x) {}
    T & Get() {
        return x_;
    }
    T x_;
};

template <typename T>
typename T::value_type Get(T ite) {
    return ite.Get();
}

Iter<int> ite(1);
std::cout << Get<Iter<int>>(ite) << std::endl;

Iter ite(1);
std::cout << Get(ite) << std::endl;
```

```c++
struct Tru {};
struct Fal {};

template <typename T>
struct TypeTraits{
    typedef Tru is_type;
};

template <> struct TypeTraits<int>{
    typedef Fal is_type;
};

void PrintType(Tru) {
    std::cout << "Tru" << std::endl;
}

void PrintType(Fal) {
    std::cout << "Fal" << std::endl;
}

template <typename T>
void Process(T) {
    typedef typename TypeTraits<T>::is_type is_type;
    PrintType(is_type());
}

Process(int());
Process(double());
```