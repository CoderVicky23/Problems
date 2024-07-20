#include <bits/stdc++.h>
using namespace std;

long long findMax(vector <int> arr) {
    int n = arr.size();
    long long prefix_prod = (arr[0]) ? arr[0] : 1;
    long long suffix_prod = (arr[n-1]) ? arr[n-1] : 1;
    long long prod = prefix_prod;
    for (int i=1; i<n; i++) {
        if (arr[i] == 0) continue;
        prefix_prod *= arr[i];
        if (prod < prefix_prod) prod = prefix_prod;
        if (prefix_prod == 0) prefix_prod = 1;
    }
    for (int i=n-2; i>=0; i--) {
        if (arr[i] == 0) continue;
        suffix_prod *= arr[i];
        if (prod < suffix_prod) prod = suffix_prod;
    }
    return prod;
}

int main() {
    vector <int> arr = {-1, -1, -2, 4, 3};
    cout << findMax(arr) << endl;
    return 0;
}