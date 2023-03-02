#include <iostream>
using namespace std;

void removeelement(int arr[], int& size, int index) {
    while(index < size - 1) {
        swap(arr[index], arr[index + 1]);
        index++;
    }
}

void removeduplicates(int arr[], int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            while (arr[i] == arr[j] && j < size) {
                removeelement(arr, size, j);
                size--;
            }
        }
    }
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main() {
    int size = 7;
    int arr[7] = {2, 2, 2, 2, 2, 2, 2};
    removeduplicates(arr, size);
    printarray(arr, size);
}