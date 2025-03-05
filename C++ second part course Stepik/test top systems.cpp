#include <iostream>

class IShape 
{
public:
	virtual ~IShape() = default;

	virtual double area() const 	     = 0;
	virtual double perimeter() const 	 = 0; 
	virtual void draw_to_console() const = 0;
};

class Triangle : public Shape 
{

};

class Rectangle : public Shape {};

int main(int argc, char * argv[]){
	return 0;
}