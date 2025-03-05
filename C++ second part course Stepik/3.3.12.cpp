#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <functional>
#include <map>
#include <utility>


// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода 
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x, y) = f(y, x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2 
{
	using F = std::function<Result (Base*, Base*)>;
	
	// Устанавливает реализацию мультиметода
	// для типов t1 и t2 заданных через typeid
	// f - это функция или функциональный объект
	// принимающий два указателя на Base
	// и возвращающий значение типа Result
	void addImpl(std::type_index t1, std::type_index t2, std::function<Result (Base *, Base *)> f)
	{
		_functions.emplace(std::make_pair(t1, t2), f);
	}

	// Проверяет, есть ли реализация мультиметода
	// для типов объектов a и b
	bool hasImpl(Base * a, Base * b) const 
	{
		return hasHidden(a, b) || (Commutative && hasHidden(b , a));
	}

	// Применяет мультиметод к объектам
	// по указателям a и b
	Result call(Base * a, Base * b) const {
		// Возвращает результат применения реализации
		// мультиметода к a и b
		return hasHidden(a, b) ? callHidden(a, b) : callHidden(b, a);
	}

private:
	mutable std::map<std::pair<std::type_index, std::type_index>, F> _functions;

	bool hasHidden(Base * a, Base * b) const
	{
		return _functions.count({typeid(*a), typeid(*b)});
	}

	Result callHidden(Base * a, Base * b) const
	{
		return _functions[{typeid(*a), typeid(*b)}](a, b);
	}
};

// базовый класс фигуры (полиморфный)
struct Shape 
{
	virtual ~Shape() {}
	virtual bool foo() = 0;
};

// прямоугольник
struct Rectangle : Shape 
{
	bool foo() override { std::cout << __PRETTY_FUNCTION__ << std::endl; return true; }
};

//треугольник
struct Triangle : Shape 
{
	bool foo() override { std::cout << __PRETTY_FUNCTION__ << std::endl; return true; }
};

// функция для проверки пересечения двух прямоугольников
bool is_intersect_r_r(Shape * a, Shape * b) { std::cout << "R x R\n"; return true; }

// функция для проверки пересечения прямоугольника и треугольника
bool is_intersect_r_t(Shape * a, Shape * b) { std::cout << "R x T\n"; return true; }

int main(int argc, char * argv[]){
	// Мультиметод для наследников Shape
	// возвращающий bool и являющийся коммутативным	
	Multimethod2<Shape, bool, true> is_intersect;

	// Добавляем реализацию мультиметода для двух прямоугольников
	is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), is_intersect_r_r);
	
	// Добавляем реализацию мультиметода для прямоугольника и треугольника
	is_intersect.addImpl(typeid(Rectangle), typeid(Triangle), is_intersect_r_t);

	// Создаём две фигуры
	Shape * s1 = new Triangle();
	Shape * s2 = new Rectangle();

	s1->foo();
	s2->foo();

	// Проверяем, что реализация для s1 и s2 есть
	if (is_intersect.hasImpl(s1, s2))
	{
		// Вызывается функция is_intersect_r_t(s2, s1)
		bool res = is_intersect.call(s1, s2);

		// Замечание : is_intersect_r_t ожидает,
		// что первым аргументов будет прямоугольник
		// а вторым треугольник, а здесь аргументы 
		// передаются в обратном порядке.
		// Ваша реализация должна самостоятельно 
		// об этом позаботиться
	}
	return 0;
}
