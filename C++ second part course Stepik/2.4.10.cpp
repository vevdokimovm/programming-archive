#include <iostream>
#include <utility>

template<typename T, typename ...Args>
auto apply(T f, Args&&... args)
	-> decltype(f(std::forward<Args>(args)...)) 
{
	return f(std::forward<Args>(args)...);
}

int main(int argc, char * argv[]){
	auto fun = [](std::string a, std::string const & b) { return a + b; };

	std::string s("world!");

	s = apply(fun, std::string("Hello, "), s);
	std::cout << s << std::endl;
	return 0;
}