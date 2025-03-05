#include <ostream>
#include <typeinfo>


void print_values(std::ostream&) {}
// принимает произвольное число аргументов
template<class T, class... Types>
void print_values(std::ostream & os, T value, Types... args) 
{
    os << typeid(value).name() << " : " << value;
    print_values(os, args...);
}