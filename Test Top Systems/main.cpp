#include <iostream>
#include <string>
#include "IShape.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"

const double eps = 0.05;

void data_of_figure(IShape *);

void make_random_shapes()
{

	IShape * shape = nullptr;

	int ans = 0;
	do
	{
		size_t turn = rand() % 4;
		if (turn == 0) shape = new Square(rand() % 25 + eps);
		else if (turn == 1) shape = new Rectangle(rand() % 25 + eps, rand() % 25 + eps);
		else if (turn == 2) shape = new Circle(rand() % 25 + eps);
		else if (turn == 3)
		{
			double a = 0;
			double b = 0;
			double c = 0;
			do
			{
				a = rand() % 40 + eps;
				b = rand() % 40 + eps;
				c = rand() % 40 + eps;
			}
			while (!(a + b > c && a + c > b && b + c > a));
			shape = new Triangle(a, b, c);
		}

		data_of_figure(shape);
		delete shape;

		std::cout <<  "\n **** **** \n"
					  "Do you want to continue with random shapes or try your own?\n"
					  "1. I want to continue with random shapes\n"
					  "2. I want to try custom shapes\n"
					  "------------------\n"
					  "Write \"1\", \"2\"\n"
					  " : ";

		std::cin >> ans;
		std::cout << std::endl;

	}	
	while (ans == 1);
}

void make_custom_shape()
{

	std::cout << "Which figure do you want to make?\n"
					 "1. Square\n"
					 "2. Rectangle\n"
					 "3. Circle\n"
					 "4. Triangle\n"
					 "(write number of preffered oprion)\n"
					 " : ";
	int opt = 0;
	std::cin >> opt;
	IShape * shape = nullptr;

	do
	{
		if (opt == 1)
		{
			double a = 0;
			std::cout << "Enter side : ";
			std::cin >> a;
			shape = new Square(a);
		}
		else if (opt == 2)
		{
			double height = 0;
			double width = 0;
			std::cout << "Enter height and width : ";
			std::cin >> height >> width;
			shape = new Rectangle(height, width);
		}
		else if (opt == 3)
		{
			double radius = 0;
			std::cout << "Enter radius : ";
			std::cin >> radius;
			shape = new Circle(radius);
		}
		else if (opt == 4)
		{
			double a = 0;
			double b = 0;
			double c = 0;
			std::cout << "Enter sides a, b and c : ";
			std::cin >> a >> b >> c;
			shape = new Triangle(a, b, c);
		}
		
		std::cout << std::endl;
		data_of_figure(shape);
		delete shape;

		std::cout << std::endl;
		std::cout << "Which figure do you want to make?\n"
					 "1. Square\n"
					 "2. Rectangle\n"
					 "3. Circle\n"
					 "4. Triangle\n"
					 "5. I want to exit the program\n"
					 "(write number of preferred oprion)\n"
					 " : ";

		std::cin >> opt;
		std::cout << std::endl;
	}
	while (opt != 5);
}

void data_of_figure(IShape * shape)
{
	shape->draw();
	std::cout << "Figure : ";
	shape->name();
	shape->parametrs();
	std::cout << "Area : " << (*shape).area() << 
	std::endl << "Perimeter : " << (*shape).perimeter();
	std::cout << std::endl;
}

int main(int argc, char * argv[])
{
	srand((unsigned int)time(NULL));

	make_random_shapes();
	make_custom_shape();


	std::cout << "\n\n ---- ---- ---- ----\n"
				 "Made by Vasilii Evdokimov\nFarewell, stranger!\n" << std::endl;

	return 0;
}