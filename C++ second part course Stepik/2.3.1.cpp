#include <iostream>
#include <tuple>

template<size_t I, size_t J, 
		 typename Head, typename... Tail>
auto to_pair(std::tuple<Head, Tail...> const& t)
	-> decltype(std::make_pair(std::get<I>(t), std::get<J>(t)))
{
	return std::make_pair(std::get<I>(t), std::get<J>(t));
}

int main(int argc, char * argv[]){
	decltype(auto) t = std::make_tuple(0, 3.5, "Hello");
	std::pair<double, char const *> p = to_pair<1, 2>(t);
	std::cout << p.first << " " << p.second << std::endl;
	return 0;
}