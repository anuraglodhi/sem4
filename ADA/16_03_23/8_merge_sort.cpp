#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid,int high) {
    int arr2[high - low + 1];
    int l = low, r = mid+1, k = 0;
    while (l <= mid && r <= high) {
        if (arr[l] < arr[r]) arr2[k++] = arr[l++];
        else arr2[k++] = arr[r++];
    }
    while (l <= mid) arr2[k++] = arr[l++];
    while (r <= high) arr2[k++] = arr[r++];
    for (int i = low, j = 0; i <= high; i++, j++) {
        arr[i] = arr2[j];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
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
    mergeSort(arr, 0, len-1);
    print(arr, len);
}