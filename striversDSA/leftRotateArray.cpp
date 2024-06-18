#include <iostream>

using namespace std;

void print(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void leftRotate(int * arr, int k, int n) {
    int j = k%n;
    while (j--) {
        int a = arr[0];
        int i;
        for (i=1; i<n; i++) {
            arr[i-1] = arr[i];
        }
        arr[i-1] = a;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int k = 9;
    leftRotate(arr, k, n);
    print(arr, n);
    return 0;
}