#include"swap.h"

template <typename Obj>

	Obj partition(Obj arr[], Obj low, Obj high){
		Obj pivot = arr[high];
		int i = (low - 1 );

		for (int j = low; j <= high - 1; j++){
			if(arr[j] <= pivot)
			{
				i++;
				swap(&arr[i],&arr[j]);
			}			
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

template <typename Obj>

	void quicksort(Obj arr[], Obj low, Obj high){

		if (low<high)
		{

			Obj pi = partition(arr,low,high);

			quicksort(arr,low,pi-1);
			quicksort(arr,pi +1,high);
		}
	}
