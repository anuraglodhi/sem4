#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = i; j < n-1; j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    const int len = 5;
    int arr[5] = {2, 5, 8, 3, 4};
    insertionSort(arr, len);
    print(arr, len);
}
