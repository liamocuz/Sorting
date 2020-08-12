#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using insertion sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

Some info about insertion sort from Wikipedia:

Insertion sort iterates, consuming one input element each repetition, 
and growing a sorted output list. At each iteration, insertion sort removes 
one element from the input data, finds the location it belongs within the 
sorted list, and inserts it there. It repeats until no input elements remain.

Sorting is typically done in-place, by iterating up the array, growing the 
sorted list behind it. At each array-position, it checks the value there against 
the largest value in the sorted list (which happens to be next to it, in the 
previous array-position checked). If larger, it leaves the element in place and 
moves to the next. If smaller, it finds the correct position within the sorted list, 
shifts all the larger values up to make a space, and inserts into that correct position.

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

void insertionSort(vector<int> &);

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

    // Call the insertion sort algorithm here
    insertionSort(arr);

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

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}