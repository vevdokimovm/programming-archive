#include <iostream>

struct Point {
	constexpr Point(double x, double y)
		: x(x), y(y) {}

	double x = 0;
	double y = 0;
};

constexpr Point operator+(Point const& a, Point const& b){
	return Point(a.x + b.x, a.y + b.y);
}

constexpr Point operator-(Point const& a, Point const& b){
	return {a.x - b.x, a.y - b.y};
}

constexpr double operator*(Point const& a, Point const& b){
	return a.x * b.x + a.y * b.y;
}

int main(int argc, char * argv[]){
	constexpr size_t size = static_cast<size_t>(Point(2, 4) * Point(4, 3));
	int m[size];

	std::cout << size << " " << sizeof(m) / sizeof(m[0]) << " " << sizeof(m) << std::endl;
	return 0;
}