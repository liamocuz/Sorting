#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

/*
This program sorts a file of integers using merge sort.

How to use:
/.executable[0] tosort[1] sorted[2]

tosort - the path to the file that needs sorting
sorted - the path for the output of tosort after sorting

Some info about merge sort from Wikipedia:

Conceptually, a merge sort works as follows:
Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

//More Complexities\\
Worst Case:
O(n log n)

Best Case:
O(n log n)

Average:
O(n log n)

Worst Case Space:
O(n) total with O(n) auxillary
O(1) auxillary with linked lists
*/

void swap(int*, int*);

void merge(vector<int> &, int, int, int);

void mergeSort(vector<int> &, int, int);

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
    mergeSort(arr, 0, arr.size() - 1);

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

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }


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


void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 