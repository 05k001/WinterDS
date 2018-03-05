//Write a program to solve the selection problem. Let k = N/2. Draw a table showing
//the running time of your program for various values of N.

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"BubbleSort.h"
#include"Selection.h"


void test(){

	int iarray[7] = {7,5,4,3,9,8,6};

	auto numOfElement = sizeof(iarray)/sizeof(iarray[0]); 

	bubblesort(iarray,7);


	for(int i = numOfElement - 1; i >= 0; i--)
		cout << iarray[i];
};


int main(){

	test();

	int n, k;

	clock_t start, finish;

	cout << "\nEnter array Size : ";

	cin >> n;

	int *prt1 = new int[n];

	//TODO: Write a random array template function

	//for now we will just make an array with random values in it

	srand(time(0));

	for (int i=0; i<n; i++){
		*(prt1 + i) = 1 + rand() % 1000;
	}

	cout << "\n\n\t The Numbers in your array are:\n\t";

	for (int i=0; i<n; i++)
		cout << *(prt1 + i) << "\t";

	bubblesort(prt1,n);

	cout << "\n\n\t The Sorted Numbers in your array are:\n\t";

	for (int i=0; i<n; i++)
		cout << *(prt1 + i) << "\t";



	double k = n/2;

	





	return 0;


}


