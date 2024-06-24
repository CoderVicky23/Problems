#include <iostream>

using namespace std;

void print(int * arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nextPermutation(int * arr, int n) {
    int ind = -1;
    for (int i=n-2; i>=0; i--) {
        if (arr[i] < arr[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind != -1) {
        for (int i=n-1; i>= 0; i--) {
            if (arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }
    }
    int j = ind+1;
    int i = n-1;
    while (j <= i) {
        swap(arr[j], arr[i]);
        j++;
        i--;
    }
}

int main() {
    int arr[] = {1, 1, 0, 0};
    int n = sizeof(arr)/sizeof(int);
    nextPermutation(arr, n);
    print(arr, n);
    return 0;
}