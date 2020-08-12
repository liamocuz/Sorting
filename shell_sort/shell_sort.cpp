#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using shell sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

My own notes about shell sort:

Shell sort uses an insertion sort mthod, but whereas insertion sort can only sort adjacent items,
shell sort can sort items far away from each other. It creates the idea of that every hth item
is sorted. So the idea is to use insertion sort on each of the h subarrays.

Some info about shell sort from Wikipedia:

Shellsort is an optimization of insertion sort that allows the exchange of items that are far apart. 
The idea is to arrange the list of elements so that, starting anywhere, taking every hth element 
produces a sorted list. Such a list is said to be h-sorted. It can also be thought of as h interleaved 
lists, each individually sorted. Beginning with large values of h allows elements to move long distances 
in the original list, reducing large amounts of disorder quickly, and leaving less work for smaller h-sort 
steps to do. If the list is then k-sorted for some smaller integer k, then the list remains h-sorted. 
Following this idea for a decreasing sequence of h values ending in 1 is guaranteed to leave a sorted 
list in the end.

Time Complexity:
O(n^2)

//Other Complexities\\
Worst Case:
O(n^2) for worst gap sequence
O(n log^2 n) for best worst case gap sequence

Best Case:
O(n log n) most gap sequences
O(n log^2 n) for best worst case gap sequence

Average:
Depends on gap sequence

Worst Case Space:
O(n) total
O(1) auxillary

*/

void swap(int*, int*);

void shellSort(vector<int> &);

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

    // Call the shell sort algorithm here
    shellSort(arr);

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

void shellSort(vector<int> &arr)
{
    int n = arr.size();
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}