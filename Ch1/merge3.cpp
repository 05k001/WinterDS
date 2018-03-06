
#include<ctime>
#include <iostream>
#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <functional>
using namespace std;

    void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}




int main(){

    clock_t start, finish;

    // int n;

    // cout << "\nEnter array Size : ";

    // cin >> n;

    // //create a vector of the specified size with random ints

    // srand(time(0));

    // std::vector<int> randvec;


    // for (int i = 0; i<n; i++){
    //     randvec.push_back(1+rand() % 1000);
    // }

    // //Print out the Array

    // cout << "\n\n\t The Numbers in your " << randvec.size() << " number array are:\n\t";

    // for (std::vector<int>::const_iterator i = randvec.begin(); i != randvec.end(); ++i)
    //     cout << *i << "\t";

    cout << "\nEnter array Size : ";

    long n_1;

    cin >> n_1;

    int prt1 [n_1];

    //TODO: Write a random array template function

    //for now we will just make an array with random values in it

    srand(time(0));

    for (int i=0; i<n_1; i++){
        *(prt1 + i) = 1 + rand() % 1000;
    }

    cout << "\n\n\t The Numbers in your array are:\n\t";

    for (int i=0; i<n_1; i++)
        cout << *(prt1 + i) << "\t";

    int arr_size = sizeof(prt1)/sizeof(prt1[0]);

    start=clock();

   
    mergeSort(prt1, 0, arr_size);


   

    finish=clock();


    cout << "\n\n\t The Sorted Numbers in your array are:\n\t";

    for (int i=0; i<n_1; i++)
        cout << *(prt1 + i) << "\t";

    int time=finish - start;

    cout << endl; 

    cout << "The quicksort took: " << time << " Mili-seconds ?" << endl;



    int K = prt1[n_1/2];


    cout << endl;

    cout << "K = " << K << endl;








   

return 0;

}



