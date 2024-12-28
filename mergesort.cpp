#include<iostream>
using namespace std;

void MergeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

int main()
{
    int main()
     {
    int size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    cout << "Unsorted array: ";
    printArray(arr, size);

    MergeSort(arr, size);

    

    return 0;
}
}