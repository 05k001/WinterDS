//Non Recursive Merge sort
//This was an interesting approach to merge sort. I found the bottom up merge 
//algoritem and it seems to work. This is a quick self contained program to 
//impliment the iterative merge.

#include<stdlib.h>
#include<stdio.h>
 
//we need a merge function
void merge(int arr[], int l, int m, int r);
 
 //Find the min of two ints
int min(int x, int y) { return (x<y)? x :y; }
 
 

void mergeSort(int arr[], int n)
{
   int sizeo;  
                   
   int left_arr;
                  
 
//Bottom Up Merge
   for (sizeo=1; sizeo<=n-1; sizeo = 2*sizeo)
   {
     
       for (left_arr=0; left_arr<n-1; left_arr += 2*sizeo)
       {
           int mid = left_arr + sizeo - 1;
 
           int right_end = min(left_arr + 2*sizeo - 1, n-1);
 
           merge(arr, left_arr, mid, right_end);
       }
   }
}
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
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
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {9, 9, 9, 5, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printArray(arr, size);
 
    mergeSort(arr, size);

    printArray(arr, size);
    return 0;
}