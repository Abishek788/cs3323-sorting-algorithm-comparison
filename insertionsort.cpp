
// Name: Abishek KC
// CS3323 – Programming Project 3
// Insertion Sort Implementation

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
        cerr << "Usage: ./insertionsort <inputfile.txt>" << endl;
        return 1;
    }

    string filename = argv[1];
    vector<int> data = readInput(filename);

    insertionSort(data);

    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
