
// Name: Abishek KC
// CS3323 – Programming Project 3
// Selection Sort Implementation

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
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
        cerr << "Usage: ./selectionsort <inputfile.txt>" << endl;
        return 1;
    }

    string filename = argv[1];
    vector<int> data = readInput(filename);

    selectionSort(data);

    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
