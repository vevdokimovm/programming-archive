#include <iostream>
#include <functional>

template<class F>
void for_each_int(int * p, int * q, F f)
{
	for ( ; p!= q; ++p) f(*p);
}

int main(int argc, char * argv[]){
	int m[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	std::function<void (int &)> square_fun = [](auto & x) -> void { x *= x; };

	for (int x : m) std::cout << x << " ";
	std::cout << std::endl;
	for_each_int(m, m + 10, square_fun);
	for (int x : m) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}