#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


// time complexity O(nlogn + n);
// using sort function
int foo(int * arr, int n) {
    sort(arr, arr+n);   // O(nlogn)
    int left = 0;
    int right = 0;
    int count = 1;
    int maxi = 1;
    while (right < n) {  // O(n);
        if (arr[right] == arr[left]) {
            right++;
        } else if (arr[right] == arr[left]+1) {
            count++;
            right++;
        } else {
            maxi = max(maxi, count);
            count = 1;
            left = right;
            right++;
        }
    }
    return maxi;
}

int fooSet(int * arr, int n) {
    unordered_set <int> hash;
    for (int i=0; i<n; i++) {
        hash.insert(arr[i]);
    }
    int count = 1;
    int maxi = 1;
    for (auto i: hash) {
        if (hash.find(i-1) == hash.end()) {
            count = 1;
            int k = i + 1;
            while (hash.find(k) != hash.end()) {
                count++;
                k++;
            }
            maxi = max(maxi, count);
        }
    }
    return maxi;
}

int main() {
    int arr[] = {100, 102, 100, 101, 103, 104, 105, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int n = sizeof(arr)/sizeof(int);
    cout << fooSet(arr, n) << endl;
    return 0;
}