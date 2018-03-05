//Testing the Memory Cell function template

#include<iostream>
#include"Whatdoo.h"
#include<string>

using namespace std;

int main(){

	MemoryCell<int> a = MemoryCell<int>{1};

	//a.write(1);

	cout << a.read() << endl;

	MemoryCell<string> * b;

	b = new MemoryCell<string> { "Hello" };



	//b->write("Whatdoo");


	cout << b->read() << endl;













	return 0;
}