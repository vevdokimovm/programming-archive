#include <iostream>

struct A {
	A() = default;
	A(A const &) { std::cout << __PRETTY_FUNCTION__ << std::endl;}
	A& operator=(A const &) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
	A(A&&) {std::cout << __PRETTY_FUNCTION__ << std::endl; }
	A& operator=(A&&) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
};

int main(int argc, char * argv[]){
	A a, b;
	b = a;
	b = static_cast<A&>(a);
	b = static_cast<A&&>(a);
	b = std::move(a);
	return 0;
}