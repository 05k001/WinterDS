#include<iostream>
#include"Stack.h"

//We implimented stacks last quarter so I drew on the code from the syllabus.
//I had the genius idea of modifying the push function to compare the top of the stack
//and then push the smallest number on last. Then getMin() would just have to look at the top
//of the stack. I think this makes the push cost more than O(1) but I cant think of a 
//faster way to getMin() in O(1) //TODO: Fix seg faults....:/


using namespace std;


int main ( ){

	Stack<int> s;

	cout << s.isEmpty();

	s.push(1);
	s.pop();
	s.top();
	s.push(2);
	cout << s.isEmpty();

	cout << s.getMin();

	s.push(1);

	s.push(3);

	cout << s.getMin();


	return 0;
}