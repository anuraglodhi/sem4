#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low, right = high;
    while (left <= right) {
        while (arr[left] <= pivot) left++;
        while (arr[right] > pivot) right--;
        if (right > left) swap(arr[left], arr[right]);
    }
    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}

void quicksort(int arr[], int low, int high) {
    if(low >= high) return;
    int part = partition(arr, low, high);
    quicksort(arr, low, part-1);
    quicksort(arr, part+1, high);
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
    quicksort(arr, 0, len-1);
    print(arr, len);
}