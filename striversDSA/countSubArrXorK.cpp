#include <bits/stdc++.h>
using namespace std;

int countXOR(vector <int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int xoro = 0;
    for (int i=0; i<n; i++) {
        xoro = 0;
        for (int j=i; j<n; j++) {
            xoro ^= arr[j];
            if (xoro == k) count++;
        }
    }
    return count;
}

int countSubXor(vector <int>& arr, int k) {
    int xr = 0;
    unordered_map <int, int> hash;
    hash[xr]++;
    int count = 0;
    for (int i=0; i<arr.size(); i++) {
        xr ^= arr[i];
        int x = xr^k;
        count += hash[x];
        hash[xr]++;
    }
    return count;
}

int main() {
    vector <int> arr = { 4, 2, 2, 6, 4};
    int k = 6;
    cout << countXOR(arr, k) << endl;
    cout << countSubXor(arr, k) << endl;
    return 0;
}