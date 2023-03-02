#include <iostream>
using namespace std;

int search(int arr [], int n,  int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i+1;
        }
    }
    return 0;
}

int main() {
    int arr[10] = {2, 4, 5, 7, 5, 4, 3, 5, 6, 7};
    int pos = search(arr, 10, 6);
    if (pos == 0) {
        cout << "Element not found" << endl;
    }
    else {
        cout << "Element found at " << pos << endl;
    }
}