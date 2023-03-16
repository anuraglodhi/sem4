#include <iostream>
using namespace std;

int maxIter(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int maxRec(int arr[], int max, int n) {
    if(n <= 0) return max;
    int max2= maxRec(arr, max, n-1);
    return (arr[n-1] > max2 ? arr[n-1] : max2);
}

int main() {
    const int l = 5;
    int arr[l] = {3,76,30,2,78};
    cout << maxIter(arr, l) << endl;
    cout << maxRec(arr, arr[0], l) << endl;
}