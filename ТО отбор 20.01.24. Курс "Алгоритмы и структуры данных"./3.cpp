#include <iostream>
#include <vector>
#include <iomanip>

int main() {
	int n = 0;
	std::cin >> n;
	std::vector<double> p(n);
	for (int i = 0; i < n; ++i) 
	{
		std::cin >> p[i];
	}

	double s = 0;
	for (int i = 0; i < n - 1; ++i) 
	{
		s += (p[i] + p[i + 1]) / 2.0;
	}
	double h = s / (n - 1);

	std::cout << std::setprecision(4) <<
	 (double)h << std::endl;
	return 0;
}