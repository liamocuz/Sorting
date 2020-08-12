#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using bubble sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

Some info about bubble sort from Wikipedia:

Bubble sort, sometimes referred to as sinking sort, is a simple sorting 
algorithm that repeatedly steps through the list, compares adjacent elements 
and swaps them if they are in the wrong order. The pass through the list is 
repeated until the list is sorted. The algorithm, which is a comparison sort, 
is named for the way smaller or larger elements "bubble" to the top of the list.

Time Complexity:
O(n^2) 

Space Complexity:
O(1)


//More Complexities\\
Worst Case:
O(n^2) comparisons
O(n^2) swaps

Best Case:
O(n) comparisons
O(1) swaps

Average:
O(n^2) comparisons
O(n^2) swaps

Worst Case Space:
O(n) total
O(1) auxillary
*/

void swap(int*, int*);

void bubbleSort(vector<int> &);

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

    // Call the bubble sort algorithm here
    bubbleSort(arr);

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

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])  
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 