#pragma once

#include <cmath>
#include "Triangle.hpp"

using std::sqrt;

namespace mo 
{
	double square(double x) { return x * x; }
}

Triangle::Triangle()
	: _a(0), _b(0), _c(0) {};

Triangle::Triangle(double a, double b, double c)
	: _a(a), _b(b), _c(c) {}

// Copy Constructor
Triangle::Triangle(Triangle const & triangle) = default;

// Move Constructor
Triangle::Triangle(Triangle && triangle) = default;

// Assignment Operator
Triangle & Triangle::operator=(Triangle const & triangle) = default;

// Move Assignment Operator 
Triangle & Triangle::operator=(Triangle &&) = default;

//Destructor
Triangle::~Triangle() = default;

std::tuple<double, double, double> Triangle::get_sides() const
{
	return std::make_tuple(_a, _b, _c);
}

double Triangle::get_side_a() const { return _a; }
double Triangle::get_side_b() const { return _b; }
double Triangle::get_side_c() const { return _c; }
double & Triangle::get_side_a() { return _a; }
double & Triangle::get_side_b() { return _b; }
double & Triangle::get_side_c() { return _c; }

void Triangle::set_sides(std::tuple<double, double, double> sides)
{
	this->_a = std::get<0>(sides);
	this->_b = std::get<1>(sides);
	this->_c = std::get<2>(sides);
}

void Triangle::set_sides(double _a, double _b, double _c)
{
	this->_a = _a;
	this->_b = _b;
	this->_c = _c;
}

double Triangle::perimeter() const
{
	return get_side_a() + get_side_b() + get_side_c();
}

double Triangle::area() const
{
	double p = perimeter() / 2;
	return std::sqrt(p * (p - get_side_a()) * (p - get_side_b()) * (p - get_side_c()));
}

// I don't draw your exact triangle 
// I draw triangle with arithmetical mean of your triangle's sides
// and make him isosceles triangle 
void Triangle::draw() const
{
	double a = this->get_side_a();
	double b = this->get_side_b();
	double c = this->get_side_c();

	// double x = (mo::square(b) - mo::square(c) + mo::square(a)) / (2 * a);
	// double y = std::sqrt(mo::square(b) - mo::square(x));
	

	size_t side = (a + b + c) / 3;
	if (side <= 2) { std::cout << " /\\\n/  \\\n----" << std::endl; return; }
	if (side % 2 == 0) ++side;

	for (size_t i = 0; i < side; ++i) std::cout << ' ';
	std::cout << '*' << std::endl;
	
	size_t space_from_left = side - 1;
	size_t space_between = 1;
	for (size_t i = 0; i < side; ++i){
		if (i == side - 1){
			std::cout << '*';
			for (size_t j = 0; j < space_between; ++j) std::cout << '*';
			std::cout << '*';
		}
		else {
			for (size_t j = 0; j < space_from_left; ++j) std::cout << ' ';
			std::cout << '*';
			for (size_t k = 0; k < space_between; ++k) std::cout << ' ';
			std::cout << '*';
			--space_from_left;
			space_between += 2;
		}
		std::cout << std::endl;
	}

}

void Triangle::name() const { std::cout << "Triangle" << std::endl; }

void Triangle::parametrs() const
{
	std::cout << "First side  : " << get_side_a() << std::endl <<
				 "Second side : " << get_side_b() << std::endl <<
				 "Third side  : " << get_side_c() << std::endl;
}

std::istream & operator>>(std::istream & rIs, Triangle & rTriangle)
{
	return rIs >> rTriangle.get_side_a() >> rTriangle.get_side_b() >> rTriangle.get_side_c();
}

std::ostream & operator<<(std::ostream & rOs, Triangle const & rTriangle)
{
	return rOs << rTriangle.get_side_a() << rTriangle.get_side_b() << rTriangle.get_side_c();
}

bool operator==(Triangle const & rcTriangle1, Triangle const & rcTriangle2)
{
	return ((rcTriangle1.get_side_a() == rcTriangle2.get_side_a()) &&
			(rcTriangle1.get_side_b() == rcTriangle2.get_side_b()) &&
			(rcTriangle1.get_side_c() == rcTriangle2.get_side_c()));
}

bool operator!=(Triangle const & rcTriangle1, Triangle const & rcTriangle2)
{
	return !(rcTriangle1 == rcTriangle2);
}