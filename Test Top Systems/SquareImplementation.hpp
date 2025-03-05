#pragma once

#include "Square.hpp"

Square::Square() = default;

Square::Square(double side)
	: _side(side) {}

// Copy constructor
Square::Square(Square const & rcSquare) = default;

// Move constructor
Square::Square(Square && Square) = default;

// Assignment Operator
Square & Square::operator=(Square const & rcSquare) = default;

// Move Assignment Operator 
Square & Square::operator=(Square && square) = default;

// Destructor
Square::~Square() = default;

double Square::get_side() const { return _side; }
double & Square::get_side() { return _side; }

void Square::set_side(double new_side) { _side = new_side; }

double Square::area() const
{
	double side = get_side();
	return side * side;
}

double Square::perimeter() const 
{
	return 4 * get_side();
}

void Square::draw() const 
{
	size_t side = std::max(this->get_side(), 1.0);

	if (side == 1) std::cout << '*' << std::endl;
	else if (side == 2) std::cout << "* *\n* *" << std::endl;
	else {
		for (size_t i = 0; i < side; ++i){
			if (i == side - 1) std::cout << '*';
			else std::cout << "* ";
		}

		std::cout << std::endl;
		for (size_t i = 0; i < side - 2; ++i){ 
			for (size_t j = 0; j < side; ++j){
				if (j == 0) std::cout << "* ";
				else if (j == side - 1) std::cout << '*';
				else std::cout << "  ";
			}
			std::cout << std::endl;
		}

		for (size_t i = 0; i < side; ++i){
			if (i == side - 1) std::cout << '*';
			else std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

void Square::name() const { std::cout << "Square" << std::endl; }

void Square::parametrs() const
{
	std::cout << "Side : " << get_side() << std::endl;
}

std::istream & operator>>(std::istream & rIs, Square & rSquare)
{
	return rIs >> rSquare.get_side();
}

std::ostream & operator<<(std::ostream & rOs, Square const & rcSquare)
{
	return rOs << rcSquare.get_side();
}

bool operator==(Square const & rcSquare1, Square const & rcSquare2)
{
	return rcSquare1.get_side() == rcSquare2.get_side();
}

bool operator!=(Square const & rcSquare1, Square const & rcSquare2)
{
	return !(rcSquare1 == rcSquare2);
}

Square operator+(Square const & rcSquare1, Square const & rcSquare2)
{
	return Square(rcSquare1.get_side() + rcSquare2.get_side());
}

