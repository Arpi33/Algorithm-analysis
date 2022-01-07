/* C++ implementation of QuickSort */
#include<iostream>
#include<cstdlib>
#include <bits/stdc++.h>
#include<ctime>
#include<chrono>
using namespace std;


// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int randPivotPartition(int arr[], int low, int high)
{
	int randPiv, n, temp;

	//randomize the number to modulus with
	n = rand();

	//to randomize the value of the pivot from the array
	randPiv = low + n%(high-low + 1);
	swap(arr[high], arr[randPiv]);

	return partition(arr, low, high);
}

/* The main function that implements QuickSort with RANDOM PIVOT
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSortRandomPivot(int arr[], int low, int high)
{
	int pi;

	if (low < high)
	{
		//cout<<"Random Pivot Test works!"<<endl;

		pi = randPivotPartition(arr, low, high);

		// Separately sort elements before
		// partition and after partition

		quickSortRandomPivot(arr, low, (pi - 1));
		quickSortRandomPivot(arr, (pi + 1), high);
	}
}



/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
    srand(time(0));
    int n=1000000;
	int* arr = new int [n];


	
	//set random elements in the array
	for(int x= 0 ; x< n; x++)
    {
        arr[x] = rand() % RAND_MAX;
    }

    //DISPLAY RESULT MENU
	//for Random Pivot
	cout<<"\n======================="<<endl;
    cout<<"Quick Sort Random Pivot"<<endl;




	auto start = chrono::system_clock::now();

	quickSortRandomPivot(arr, 0, n - 1);
	//cout<<"\nSorted array: \n";
	//printArray(arr, n);

    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;

    cout<<"\nDuration:"<<duration.count()<<"s\n";

	return 0;
}
