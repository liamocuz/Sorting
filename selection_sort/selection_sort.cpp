#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using selection sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

Some info about selection sort from Wikipedia:

The algorithm divides the input list into two parts: a sorted sublist of items 
which is built up from left to right at the front (left) of the list and a sublist 
of the remaining unsorted items that occupy the rest of the list. Initially, the sorted 
sublist is empty and the unsorted sublist is the entire input list. The algorithm 
proceeds by finding the smallest (or largest, depending on sorting order) element 
in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element 
(putting it in sorted order), and moving the sublist boundaries one element to the right.

Time Complexity:
O(n^2) as there are two nested loops

Space Complexity:
O(1)


//More Complexities\\
Worst Case:
O(n^2) comparisons
O(n) swaps

Best Case:
O(n^2) comparisons
O(1) swaps

Average:
O(n^2) comparisons
O(n) swaps

Worst Case Space:
O(1) Auxillary
*/

void swap(int*, int*);

void selectionSort(vector<int> &);

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

    // Call the selection sort algorithm here
    selectionSort(arr);

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

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int mindex;

    for (int i = 0; i < n - 1; i++)
    {
        mindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mindex])
                mindex = j;
        }
            
        swap(&arr[mindex], &arr[i]);
    }
}

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 