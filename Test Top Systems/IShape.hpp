#pragma once

class IShape 
{
public:
	virtual ~IShape() = default;

	virtual double area() const 	     = 0;
	virtual double perimeter() const 	 = 0; 
	virtual void draw() const = 0;
	virtual void name() const = 0;
	virtual void parametrs() const = 0;
};