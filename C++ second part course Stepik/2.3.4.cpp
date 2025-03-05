#include <iostream>
#include <functional>

template<class F>
int * find_if(int * p, int * q, F f){
	for ( ; p != q; ++p)
		if (f(*p))
			return p;
	return q;
}

int main(int argc, char * argv[]){
	int primes[5] = {2, 3, 5, 7, 11};
	int m[10] = {0, 0, 1, 1, 4, 6, 7, 8, 9, 10};

	std::function<std::function<bool (int)> (int *, int*)> gen_finder = [](int * p, int * q) 
																		-> std::function<bool (int)> 
	{ 
		return [p, q](int x) 
				-> bool {
			int * s = p;
			int * e = q;
			for ( ; s != e; ++s)
				if (x == *s) return true;
			return false;
		};
	};

	std::cout << gen_finder(primes, primes + 10)(7) << std::endl;

	int * first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
	std::cout << *first_prime << std::endl;
	return 0;
}