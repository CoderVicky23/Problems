#include <iostream>
using namespace std;

int getMaxPoints(int * arr, int k, int n) {
    int lsum = 0;
    int rsum = 0;
    for (int i=0; i<k; i++) {
        lsum += arr[i];
    }
    int max_sum = lsum;
    if (k <= n) return max_sum;
    for (int i=1; i<=k; i++) {
        lsum -= arr[k-i];
        rsum += arr[n-i];
        cout << "Max Sum at i=" << i-1 << " " << max_sum << endl;
        max_sum = max(max_sum, lsum + rsum);
    }
    return max_sum;
}

int main() {
    int arr[] = {6, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    int k = 4;
    cout << getMaxPoints(arr, k, n) << endl;
    return 0;
}