#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using quick sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

My own notes about quick sort:

A lot can be changed about quick sort to try and improve it. The partition choice can
be different, but that may or may not create a better algorithm. A balance must be achieved
for the best results. It can be fragile, meaining a simple mistake in implementation can have
poor results for performance.

It consists of two parts. The partition function and the sorting function. The partition functions
is the main part of the whole algorithm, as it's implementation will result in the quality of the
performance.

Some info about quick sort from Wikipedia:

Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element 
from the array and partitioning the other elements into two sub-arrays, according to 
whether they are less than or greater than the pivot. The sub-arrays are then sorted 
recursively. This can be done in-place, requiring small additional amounts of memory 
to perform the sorting.

Quicksort is a comparison sort, meaning that it can sort items of any type for which 
a "less-than" relation (formally, a total order) is defined. Efficient implementations 
of Quicksort are not a stable sort, meaning that the relative order of equal sort items 
is not preserved.

Time Complexity:
O(n log n) to O(n^2) at worst

//Other Complexities\\
Worst Case:
O(n^2) time

Best Case:
O(n log n) simple partition
O(n) three way partitiond equal keys

Average:
O(n log n)

Worst Case Space:
O(n) auxillary naive
O(log n) auxillary

*/

void quickSort(vector<int> &, int, int);

int partition(vector<int> &, int, int);

void swap(int*, int*);

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Incorrect amount of arguments." << endl;
        return EXIT_FAILURE;
    }

    // Reading unsorted file to a vector
    ifstream inFile;
    inFile.open(argv[1], ios::in);

    istream_iterator<int> start(inFile), end; //this is the coolest thing ever
    vector<int> arr (start, end);

    inFile.close();

    // Call the quick sort algorithm here
    quickSort(arr, 0, arr.size() - 1);

    // Writing sorted vector to a file
    ofstream outFile;
    outFile.open(argv[2], ios::out);

    for (int i = 0; i < arr.size(); i++)
    {
        outFile << arr[i] << endl;
    }

    outFile.close();

    return EXIT_SUCCESS;
}

void quickSort(vector<int> &arr, int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int i, j, pivot;

    pivot = arr[high];
    i = (low - 1);

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 