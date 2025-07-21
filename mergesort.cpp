
// Name: Abishek KC
// CS3323 – Programming Project 3
// Merge Sort Implementation (with randomized mid-point concept for learning)

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftVec(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightVec(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] <= rightVec[j]) arr[k++] = leftVec[i++];
        else arr[k++] = rightVec[j++];
    }

    while (i < leftVec.size()) arr[k++] = leftVec[i++];
    while (j < rightVec.size()) arr[k++] = rightVec[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + rand() % (right - left);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        cerr << "Usage: ./mergesort <inputfile.txt>" << endl;
        return 1;
    }

    srand(time(0));
    string filename = argv[1];
    vector<int> data = readInput(filename);

    mergeSort(data, 0, data.size() - 1);

    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
