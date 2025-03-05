#include <iostream>

template<class S>
S&& forward(typename std::remove_reference<S>::type& a)
{
	return static_cast<S&&>(a);
}

int main(int argc, char * argv[]){
	return 0;
}