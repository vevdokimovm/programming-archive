#pragma once

#include <iostream>
#include <utility>
#include "IShape.hpp"

using std::ostream;
using std::istream;

class Rectangle : public IShape
{
public:
	Rectangle();
	Rectangle(double, double);
	// Copy Constructor
	Rectangle(Rectangle const &);
	// Move Constructor
	Rectangle(Rectangle &&);
	// Assignment Operator
	Rectangle & operator=(Rectangle const &);
	// Move Assignment Operator
	Rectangle & operator=(Rectangle &&);
	// Destructor
	~Rectangle();

	std::pair<double, double> get_sides() const;

	void set_sides(std::pair<double, double>);
	void set_sides(double, double);
	void set_height(double);
	void set_width(double);

	double area() const override;
	double perimeter() const override;
	void draw() const override;
	void name() const override;
	void parametrs() const override;

	friend std::istream & operator>>(std::istream &, Rectangle &);
	friend std::ostream & operator<<(std::ostream &, Rectangle const &);
	friend bool operator==(Rectangle const &, Rectangle const &);
	friend bool operator!=(Rectangle const &, Rectangle const &);

private:

	double get_height() const;
	double get_width() const;
	double & get_height();
	double & get_width();

	double _height = 0;
	double _width = 0;
};

#include "RectangleImplementation.hpp"