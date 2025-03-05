#include <iostream>
#include <algorithm>
#include <vector>

template<class FwdIt>
FwdIt remove_nth(FwdIt p, FwdIt q, size_t n)
{
	p = std::find_if(p, q, [n](int x) { return x == n; });
	if (p != q)
		for (FwdIt i = p; ++i != q; )
			if (n != *i)
				*p++ = std::move(*i);
	return p;
}

int main(int argc, char * argv[])
{
	// std::vector<int> v = {2, 5, 1, 5, 8, 5, 2, 5, 8};
	// for (auto elem : v) std::cout << elem << ' ';
	// std::cout << std::endl;
	
	// remove(v.begin(), v.end(), 5);
	// for (auto elem : v) std::cout << elem << ' ';
	// std::cout << std::endl;
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (auto elem : v) std::cout << elem << ' ';
	std::cout << std::endl;
	v.erase(remove_nth(v.begin(), v.end(), 5), v.end());
	for (auto elem : v) std::cout << elem << ' ';
	std::cout << std::endl;
	//теперь в v = {0,1,2,3,4,6,7,8,9,10};	
	return 0;
}