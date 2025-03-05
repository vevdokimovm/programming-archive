#include <iostream>

class String {
public:
	// Конструктор по умолчанию 
	String() = default;

	// Конструктор копирования
	String(String const & s) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	
	// Перемещающий конструктор
	String(String && s) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
	
	// Оператор присваивания
	String & operator=(String const & s) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
	
	// Перемещающий оператор присваивания
	String & operator=(String && s) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
	
	// Деструктор
	~String() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

private:
};


String & fun1(String & s)
{
	return s;
}

String && fun2(String & s)
{
	return std::move(s);
}

String fun3(String & s){
	return std::move(s);
}

String fun4(String s){
	return std::move(s);
}

String fun5(String s){
	return std::forward<String>(s);
}

String && fun6(String && s){
	return std::move(s);
}

String fun7(String && s){
	return s;
}

int main(int argc, char * argv[]){
	String s;
	std::cout << std::endl;
	std::cout << " -- fun1 --\n", fun1(s), std::cout << std::endl;
	std::cout << " -- fun2 --\n", fun2(s), std::cout << std::endl;
	std::cout << " -- fun3 --\n", fun3(s), std::cout << std::endl;
	std::cout << " -- fun4 --\n", fun4(s), std::cout << std::endl;
	std::cout << " -- fun5 --\n", fun5(s), std::cout << std::endl;
	std::cout << " -- fun6 --\n", fun6(String()), std::cout << std::endl;
	std::cout << " -- fun7 --\n", fun7(String()), std::cout << std::endl;
	return 0;
}