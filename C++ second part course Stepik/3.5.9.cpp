#include <iostream>
#include <algorithm>


int main(int argc, char * argv){
	std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	v.erase(remove_nth(v.begin(), v.end(), 5), v.end());
	return 0;
}