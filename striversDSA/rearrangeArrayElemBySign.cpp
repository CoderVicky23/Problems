#include <iostream>

using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rearrange(int arr[], int n) {
    int * pos = new int[n/2];
    int * neg = new int[n/2];
    int j = 0;
    int k = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] > 0) {
            pos[j++] = arr[i];
        }
        else {
            neg[k++] = arr[i];
        }
    }
    for (int i=0; i<n/2; i++) {
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}

int main() {
    int arr[] = {3, 1, -2, -5, 2, -4};
    int n = sizeof(arr)/sizeof(int);
    rearrange(arr, n);
    print(arr, n);
    return 0;
}