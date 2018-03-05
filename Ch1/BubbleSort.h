//A Bubble Sort Template

#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;



template<class X>

	void bubblesort_debug(X *items, int count)
	{
		X t;

		for(int a=1; a<count; a++)
			for(int b=count-1; b>=a; b--) 
				if(items[b-1] > items[b]){
					for(int i = count - 1; i >= 0; i--)
						cout << items[i];
				cout << endl;
				sleep_for(seconds(2));
					t = items[b-1];
					items[b-1] = items[b];
					items[b] = t;
				}
	}

	template<class X>

	 	void bubblesort(X *items, int count)
	{
		X t;

		for(int a=1; a<count; a++)
			for(int b=count-1; b>=a; b--) 
				if(items[b-1] > items[b]){
					t = items[b-1];
					items[b-1] = items[b];
					items[b] = t;
				}
	}

