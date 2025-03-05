#include <cstddef> // size_t

template<class T, size_t S>
size_t array_size(T (&a)[S]){
    return S;
}