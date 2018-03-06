//Fig 7.17 from the book. A quicksort template.

//Im forgoing the if then logic for insertion sort with arrays less than 10

#include<vector>
#include"median3.h"





template <typename CompDawg>

	void quicksort( CompDawg a[], int left, int right){

		const CompDawg & pivot = median3( a, left, right);


		//Lets build a partition 

		int i = left, j = right - 1;

		for( ; ; )
		{
			while( a[i++] < pivot) { }
			while( pivot < a[--j]) { }
				if( i < j )
					std::swap(a[i],a[j]);
				else
					break;

		}


		std::swap( a[i], a[ right -1 ]); 

		quicksort(a,left,right);
		quicksort(a, i + 1, right);
	}
