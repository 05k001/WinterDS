#include "Hash.cpp"
#include "Employee.cpp"
#include <iostream>


int timeof( void (*f))


int main() {

	clock_t start, finish;


	HashTable<Employee> h1;
	Employee e1("Eric", 10, 1);
	Employee e2("Jeff", 11, 2);
	Employee e3("Sally", 12, 3);
	Employee e4("Ethel", 13, 4);

	h1.insert(e1);
	h1.insert(e2);
	h1.insert(e3);

	if (h1.contains(e1))
		std::cout << "E1 is in table" << std::endl;
	else
		std::cout << "E1 is not in table" << std::endl;
	if (h1.contains(e4))
		std::cout << "E4 is in table" << std::endl;
	else
		std::cout << "E4 is not in table" << std::endl;

	h1.remove(e1);
	if (h1.contains(e1))
		std::cout << "E1 is in table" << std::endl;
	else
		std::cout << "E1 is not in table" << std::endl;


	h1.insert(e1);

	std::cout << h1.contains(e1) << std::endl;

	h1.makeEmpty();

	std::cout << h1.contains(e1) << std::endl;



}