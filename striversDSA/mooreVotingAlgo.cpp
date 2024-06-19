#include <iostream>

using namespace std;

int mooreVotingAlgo(int * arr, int n) {
    int element;
    int count = 0;
    for (int i=0; i<n; i++) {
        if (count == 0) {
            element = arr[i];
            count++;
        } else if (element == arr[i]) {
            count++;
        } else {
            count--;
        }
    }
    return element;
}

int main() {
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << mooreVotingAlgo(arr, n) << endl;
    return 0;
}