#pragma once

#include <iostream>
#include "IShape.hpp"

class Square : public IShape 
{
public:
	Square();
	explicit Square(double side);
	// Copy constructor
	Square(Square const &);
	// Move constructor
	Square(Square &&);
	// Assignment Operator
	Square & operator=(Square const &);
	// Move Assignment Operator
	Square & operator=(Square &&);
	//Destructor
	~Square();

	double get_side() const;
	double & get_side();

	void set_side(double);

	double area() const override;
	double perimeter() const override;
	void draw() const override;
	void name() const override;
	void parametrs() const override;

	friend std::istream & operator>>(std::istream &, Square &);
	friend std::ostream & operator<<(std::ostream &, Square const &);
	friend bool operator==(Square const &, Square const &);
	friend bool operator!=(Square const &, Square const &);
	friend Square operator+(Square const &, Square const &);

private:
	double _side = 0;
};

#include "SquareImplementation.hpp"