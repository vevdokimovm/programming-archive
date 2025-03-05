#include <iostream>


// Весь вывод должен осуществляться в поток out,
// переданный в качестве параметра.
//
// Можно заводить любые вспомогательные функции,
// структуры или даже изменять сигнатуру flatten,
// но при этом все примеры вызова из задания должны
// компилироваться и работать.

template<typename T>
void flatten(const T& object, std::ostream& out){
        out << object << ' ';
}

template <typename T>
void flatten(const Array<T>& arr, std::ostream& out){
    for (size_t i = 0; i < arr.size(); ++i)
        flatten(arr[i], out);
}