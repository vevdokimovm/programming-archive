#pragma once

#include "Circle.hpp"

Circle::Circle() = default;

Circle::Circle(double _radius)
	: _radius(_radius) {}

Circle::Circle(Circle const & rCircle) = default;

Circle::Circle(Circle && circle) = default;

Circle & Circle::operator=(Circle const & rCircle) = default;

Circle & Circle::operator=(Circle && circle) = default;

Circle::~Circle() = default;

double Circle::get_radius() const { return _radius; }
double & Circle::get_radius() { return _radius; }

void Circle::set(double _radius) { this->_radius = _radius; }


double Circle::area() const { return PI * _radius * _radius; }
double Circle::perimeter() const { return PI * 2 * _radius; }
void Circle::draw() const
{
	double radius = get_radius();
	double m = 2;
	double pivot = 0;

	for (int i = -radius; i <= radius; ++i) 
	{
		for (int j = -radius; j <= radius; ++j) 
		{
			pivot = ((i * m) / radius) * ((i * m) / radius) + (j / radius) * (j / radius);

			if (pivot > 0.95 && pivot < 1.08) std::cout << '*';
			else std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

void Circle::name() const { std::cout << "Circle" << std::endl; }

void Circle::parametrs() const { std::cout << "Radius : " << get_radius() << std::endl; }

std::istream & operator>>(std::istream & rIs, Circle & rCircle)
{
	return rIs >> rCircle.get_radius();
}

std::ostream & operator<<(std::ostream & rOs, Circle const & rcCircle)
{
	return rOs << rcCircle.get_radius();
}

bool operator==(Circle const & rcCircle1, Circle const & rcCircle2)
{
	return rcCircle1.get_radius() == rcCircle2.get_radius();
}

bool operator!=(Circle const & rcCircle1, Circle const & rcCircle2)
{
	return !(rcCircle1 == rcCircle2);
}
