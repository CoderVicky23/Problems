#include <iostream>
#include <climits>

using namespace std;

// time complexity O(n^3)
long long foo(long long arr[], int n) {
    long long maxi = 0;
    long long smaller = INT_MAX;
    long long smallest = INT_MAX;
    for (int k=0; k<n-1; k++) {
        for (int i=k+1; i<n; i++) {
            smaller = INT_MAX;
            smallest = INT_MAX;
            for (int j=k; j<=i; j++) {
                if (arr[j] < smallest) {
                    smaller = smallest;
                    smallest = arr[j];
                } else if (arr[j] < smaller) {
                    smaller = arr[j];
                }
            }
            maxi = max(maxi, smaller+smallest);
        }
    }
    return maxi;
}

// time complexity O(N^2)
long long foo2(long long arr[], int n) {
    long long maxi = 0;
    long long smaller = INT_MAX;
    long long smallest = INT_MAX;
    for (int i=0; i<n-1; i++) {
        smaller = arr[i];
        smallest = arr[i+1];
        for (int j=i; j<n; j++) {
            if (arr[j] < smallest) {
                smaller = smallest;
                smallest = arr[j];
            } else if (arr[j] < smaller) {
                smaller = arr[j];
            }
            maxi = max(maxi, smaller + smallest);
        }
    }
    return maxi;
}

// time complexity O(N)
long long foo3(long long arr[], int n) {
    int i=0;
    int j=1;
    long long maxi = 0;
    while (j < n) {
        maxi = max(maxi, arr[i]+arr[j]);
        j++;
        i++;
    }
    return maxi;
}

int main() {
    long long arr[] = {5, 3, 9, 6, 8, 8};
    int n = sizeof(arr)/sizeof(long long);
    long long result = foo3(arr, n);
    cout << result << endl;
    return 0;
}