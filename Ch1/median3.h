//Median helper function for quicksort

#include<vector>
#include<iostream>
#include"swap.h"

template<typename CompDawg>

	const CompDawg median3(CompDawg a[], int left, int right)

	{

		//find the middle index of the array

		int center = (left + right) / 2;

		//Main logic of the function

		if ( a[center] < a[left] )
			std::swap(a[left], a[center]);

		if ( a[right] < a[left] )
			std::swap(a[left],a[right]);

		if( a[right] < a[center])
			std::swap(a[center], a[right]);


			//Here is where the povit will get placed

		std::swap(a[center],a[right-1]);

		return a[right-1];	 

	}

	