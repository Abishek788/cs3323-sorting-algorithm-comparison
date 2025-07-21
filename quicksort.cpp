
// Name: Abishek KC
// CS3323 – Programming Project 3
// Quick Sort Implementation with Random Pivot

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> readInput(const string& filename) {
    vector<int> arr;
    ifstream infile(filename);
    int number;
    while (infile >> number) {
        arr.push_back(number);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ./quicksort <inputfile.txt>" << endl;
        return 1;
    }

    srand(time(0));
    string filename = argv[1];
    vector<int> data = readInput(filename);

    quickSort(data, 0, data.size() - 1);

    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
