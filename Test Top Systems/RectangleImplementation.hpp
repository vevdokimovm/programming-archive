#pragma once

#include "Rectangle.hpp"

Rectangle::Rectangle()
	: _height(0), _width(0) {}

Rectangle::Rectangle(double _height, double _width)
	: _height(_width), _width(_width) {}

// Copy Constructor
Rectangle::Rectangle(Rectangle const & rRectangle) = default;

// Move Constructor
Rectangle::Rectangle(Rectangle && rectangle) = default;

// Assignment Operator
Rectangle & Rectangle::operator=(Rectangle const & rRectangle) = default;

// Move Assignment Operator
Rectangle & Rectangle::operator=(Rectangle && rectangle) = default;

// Destructor
Rectangle::~Rectangle() = default;

std::pair<double, double> Rectangle::get_sides() const
{
	return std::make_pair(_height, _width);
}

double Rectangle::get_height() const { return _height; }
double Rectangle::get_width() const { return _width; }
double & Rectangle::get_height() { return _height; }
double & Rectangle::get_width() { return _width; }

void Rectangle::set_sides(std::pair<double, double> sides)
{
	_height = sides.first;
	_width = sides.second;
}

void Rectangle::set_sides(double _height, double _width)
{
	this->_height = _height;
	this->_width = _width;
}


double Rectangle::area() const
{
	return get_height() * get_width();
}

double Rectangle::perimeter() const
{
	return get_height() * 2 + get_width() * 2;
}

void Rectangle::draw() const
{
	size_t height = get_height();
	size_t width = get_width();

	if (height == 1 && width == 1) std::cout << '*' << std::endl;
	else if (height == 1) {
		for (size_t i = 0; i < width; ++i) {
			if (i == width - 1) std::cout << '*';
			else std::cout << "* ";
		}
		std::cout << std::endl;
	}
	else if (width == 1) {
		for (size_t i = 0; i < height; ++i) std::cout << "*\n";
	}
	else {
		for (size_t i = 0; i < width; ++i){
			if (i == width - 1) std::cout << '*';
			else std::cout << "* ";
		}

		std::cout << std::endl;
		for (size_t i = 0; i < height - 2; ++i){ 
			for (size_t j = 0; j < width; ++j){
				if (j == 0) std::cout << "* ";
				else if (j == width - 1) std::cout << '*';
				else std::cout << "  ";
			}
			std::cout << std::endl;
		}

		for (size_t i = 0; i < width; ++i){
			if (i == width - 1) std::cout << '*';
			else std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

void Rectangle::name() const { std::cout << "Rectangle" << std::endl; }

void Rectangle::parametrs() const 
{
	std::cout << "Heihgt : " << get_height() << std::endl <<
				 "Width  : " << get_width() << std::endl;
}

std::istream & operator>>(std::istream & rIs, Rectangle & rRectangle)
{
	return rIs >> rRectangle.get_height() >> rRectangle.get_width();
}

std::ostream & operator<<(std::ostream & rOs, Rectangle const & rRectangle)
{
	return rOs << rRectangle.get_height() << rRectangle.get_width();
}

bool operator==(Rectangle const & rcRectangle1, Rectangle const & rcRectangle2)
{
	return ((rcRectangle1.get_height() == rcRectangle2.get_height()) &&
			 rcRectangle1.get_width() == rcRectangle2.get_width());
}