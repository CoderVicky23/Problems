#include <bits/stdc++.h>
using namespace std;

// using hashmap
vector <int> funn(int * arr, int n) {
    int hash[n+1] = {0};
    int repeating = -1;
    int missing = -1;
    for (int i=0; i<n; i++) {
        hash[arr[i]]++;
    }
    for (int i=1; i<n; i++) {
        if (hash[i] == 0) missing = i;
        else if (hash[i] == 2) repeating = i;
        else if (missing != -1 && repeating != -1) break;
    }
    return { repeating, missing};
}

// using maths
vector <int> fun(int * arr, int num) {
    long long n = num;
    long long SN = (n*(n+1))/2;
    long long S2N = (n * (n+1) * (2*n+1))/6;
    long long S = 0, S2 = 0;
    for (int i=0; i<n; i++) {
        S += arr[i];
        S2 += arr[i]*arr[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2/val1;
    long long x = (val1 + val2) / 2;
    long long y = val2 - x;
    return {(int) x, (int) y};
}

int main() {
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr)/sizeof(int);
    for (auto i: fun(arr, n)) {
        cout << i << endl;
    }
    return 0;
}