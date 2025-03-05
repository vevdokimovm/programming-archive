#pragma once

#include <tuple>
#include <iostream>
#include "IShape.hpp"

using std::istream;
using std::ostream;

class Triangle : public IShape 
{
public:
	Triangle();
	Triangle(double, double, double);
	// Copy Constructor 
	Triangle(Triangle const &);
	// Move Constructor
	Triangle(Triangle &&);
	// Assignment Operator
	Triangle & operator=(Triangle const &);
	// Move Assignment Operator
	Triangle & operator=(Triangle &&);
	//Destructor
	~Triangle();

	std::tuple<double, double, double> get_sides() const;

	void set_sides(std::tuple<double, double, double>);
	void set_sides(double, double, double);

	double area() const override;
	double perimeter() const override;
	void draw() const override;
	void name() const override;
	void parametrs() const override;

	friend std::istream & operator>>(std::istream &, Triangle &);
	friend std::ostream & operator<<(std::ostream &, Triangle const &);
	friend bool operator==(Triangle const &, Triangle const &);
	friend bool operator!=(Triangle const &, Triangle const &);

private:

	double get_side_a() const;
	double get_side_b() const;
	double get_side_c() const;
	double & get_side_a();
	double & get_side_b();
	double & get_side_c();

	double _a = 0;
	double _b = 0;
	double _c = 0;
};

#include "TriangleImplementation.hpp"