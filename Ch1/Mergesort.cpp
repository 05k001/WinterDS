//Mergesort?

#include<vector>
#include<iostream>
using namespace std;

template<typename CompDawg>

	void merge( CompDawg a[], CompDawg tmpArray[],
					int leftPos, int rightPos, int rightEnd )

	{

		int leftEnd = rightPos -1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;


		//Loooooooopy


		while ( leftPos <= leftEnd && rightPos <= rightEnd )
			if ( a[leftPos] <= a[rightPos])
				tmpArray [ tmpPos++ ] = std::move ( a[leftPos++]);
			else
				tmpArray [ tmpPos++ ] = std::move( a [rightPos++ ]);

		while( leftPos <= leftEnd ) //Copy rest of the first half
			tmpArray[ tmpPos++ ] = std::move(a[rightPos++]);

		//Copy tmp Array back

		for( int i = 0; i < numElements; ++i, --rightEnd)
			a[rightEnd]= std::move( tmpArray[rightEnd]);


	}

template<typename CompDawg>

	void Mergesort( CompDawg a[], CompDawg tmpArray[], int left, int right)

	{
		if (left < right)
		{

			int center = (left + right ) /2;

			Mergesort( a, tmpArray, left, center);
			Mergesort( a, tmpArray, center + 1, right);
			merge( a, tmpArray, left, center + 1, right);


		}
	}


int main(){

	//lets make an array and sort it


	int n, k;

	clock_t start, finish;

	cout << "\nEnter array Size : ";

	cin >> n;

	int *prt1 = new int[n];
	int *prt2 = new int[n];

	//New Random Seed

	srand(time(0));

	//Fill the Array with random numbers

	for (int i=0; i<n; i++){
		*(prt1 + i) = 1 + rand() % 1000;
	}


	cout << "\n\n\t The Numbers in your array are:\n\t";

	for (int i=0; i<n; i++)
		cout << *(prt1 + i) << "\t";

	start=clock();

	//bubblesort(prt1,n);

	Mergesort(prt1);

	finish=clock();

	cout << "\n\n\t The Sorted Numbers in your array are:\n\t";

	for (int i=0; i<n; i++)
		cout << *(prt1 + i) << "\t";

	int time=finish - start;

	cout << endl; 

	cout << "The Mergesort took: " << time << " Mili-seconds ?" << endl;



}
