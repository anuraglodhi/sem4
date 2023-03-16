#include <iostream>
using namespace std;

int* merge(int arr1[], int l1, int arr2[], int l2) {
    int i = 0, j = 0, k = 0;
    int* arr3 = new int[l1+l2];
    while(i < l1 && j < l2) {
        if(arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while(i < l1) {
        arr3[k++] = arr1[i++];
    }
    while(j < l2) {
        arr3[k++] = arr2[j++];
    }
    return arr3;
}

void print(int arr[], int l) {
    for (int i = 0; i < l ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int l1 = 3, l2 = 4;
    int arr1[l1] = {2,5,7};
    int arr2[l2] = {3,5,8,10};
    int* arr3;

    arr3 = merge(arr1, l1, arr2, l2);
    print(arr3, l1+l2);
    delete arr3;

}