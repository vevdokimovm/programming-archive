#include <iostream>
#include <typeinfo>
#include <list>

struct Elf {};

int main(int argc, char * argv[]){
	std::list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int>::iterator i = l.begin();
	advance(i, 5);
	std::cout << *i << std::endl;
	std::list<int>::reverse_iterator ri(i);
	std::cout << *r	i << std::endl;
	i = ri.base();
	std::cout << *i << std::endl;

	return 0;
}