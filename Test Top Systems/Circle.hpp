#pragma once

#include <iostream>
#include "IShape.hpp"


class Circle : public IShape 
{
public:
	Circle();
	Circle(double);
	// Copy Constructor 
	Circle(Circle const &);
	// Move constructor
	Circle(Circle &&);
	// Assignment Operator
	Circle & operator=(Circle const &);
	// Move Assignment Operator
	Circle & operator=(Circle &&);
	//Destructor 
	~Circle();

	double get_radius() const;
	double & get_radius();

	void set(double);

	double area() const override;
	double perimeter() const override;
	void draw() const override;
	void name() const override;
	void parametrs() const override;

	friend std::istream & operator>>(std::istream &, Circle &);
	friend std::ostream & operator<<(std::ostream &, Circle const &);
	friend bool operator==(Circle const &, Circle const &);
	friend bool operator!=(Circle const &, Circle const &);
private:
	double _radius;

	constexpr static double const PI = 3.14159265;
};

#include "CircleImplementation.hpp"