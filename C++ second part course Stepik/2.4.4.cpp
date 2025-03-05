#include <iostream>

void functionIn(int && i) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void functionIn(int & i) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

//void functionIn(int i) { std::cout << __PRETTY_FUNCTION__ << std::endl; }


void functionEx(int && i) { std::cout << __PRETTY_FUNCTION__ << std::endl; functionIn(5); }

void functionEx(int & i) { std::cout << __PRETTY_FUNCTION__ << std::endl; functionIn(5); }

//void functionEx(int i) { std::cout << __PRETTY_FUNCTION__ << std::endl; functionIn(5); }


void foo(int && i) { std::cout << __PRETTY_FUNCTION__ << std::endl; functionIn(i); }

void bar(int && i) { std::cout << __PRETTY_FUNCTION__ << std::endl; functionIn(std::move(i)); }

int main(int argc, char * argv[]){
	functionEx(std::move(100));
	std::cout << std::endl;
	int i = 100;
	//functionEx(std::move(i));
	functionEx(i);
	std::cout << std::endl;
	foo(100);
	std::cout << std::endl;
	bar(100);
	return 0;
}