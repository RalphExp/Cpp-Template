#include <iostream>
#include "traits/issame.hpp"

// tag dispatching

template<typename T>
void fooImpl(T, TrueType) {
    std::cout << "fooImpl(T,true) for int called\n";
}

template<typename T>
void fooImpl(T, FalseType) {
    std::cout << "fooImpl(T,false) for other type called\n";
}

template<typename T>
void foo(T t) {
    fooImpl(t, IsSameT<T,int>{}); // choose impl. depending on whether T is int
}

int main()
{
    foo(42); // calls fooImpl(42, TrueType)
    foo(7.7); // calls fooImpl(42, FalseType)
}