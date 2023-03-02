#include <iostream>
using namespace std;

int search(int arr[], int n, int x) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) return mid + 1;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int main() {
    int arr[5] = {2, 4, 5, 6, 7};
    int pos = search(arr, 5, 2);
    if (pos) {
        cout << "Element found at " << pos << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
}