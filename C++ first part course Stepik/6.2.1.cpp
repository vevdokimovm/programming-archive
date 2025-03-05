#include <cstddef>

// Параметры функции copy_n идут в следующем
// порядке:
//   1. целевой массив
//   2. массив источник
//   3. количество элементов, которые нужно
//      скопировать
//
// Вам нужно реализовать только функцию copy_n,
// чтобы ее можно было вызвать так, как показано
// в примере.

// put your code here
template<class TypeTo,
         class TypeFrom>
void copy_n(TypeTo * p, TypeFrom * q, size_t num){
    for (size_t i = 0; i < num; ++i){
        p[i] = TypeTo(q[i]);
    }
}