#include <iostream>
using namespace std;

int common(int arr1[], int l1, int arr2[], int l2, int arr3[]) {
    int k = 0;
    int len = 0;
    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < l2; j++) {
            if(arr1[i] == arr2[j]) {
                arr3[k++] = arr1[i];
                len++;
            }
        }
    }
    return len;
}

void print(int arr[], int l) {
    for (int i = 0; i < l ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int l1 = 3, l2 = 4;
    int arr1[l1] = {2, 4, 6};
    int arr2[l2] = {2, 5, 6, 9};
    int arr3[l1];
    int len = common(arr1, l1, arr2, l2, arr3);
    print(arr3, len);

}