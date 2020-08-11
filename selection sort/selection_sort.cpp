#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

// Want to pass in the file name to check, argc should be 2

int main (int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Incorrect amount of aarguments." << endl;
        return EXIT_FAILURE;
    }

    ifstream file;
    file.open(argv[1], ios::in);

    istream_iterator<int> start(file), end; //this is the coolest thing ever
    vector<int> arr (start, end);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    file.close();

    return EXIT_SUCCESS;
}