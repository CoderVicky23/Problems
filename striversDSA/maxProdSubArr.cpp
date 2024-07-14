#include <bits/stdc++.h>
using namespace std;

int fun(vector <int>& nums) {
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;
    for (int i=1; i<n; i++) {
        if (!prefix) prefix = 1;
        if (!suffix) suffix = 1;
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main() {
    vector <int> arr = {-2, 0};
    cout << fun(arr) << endl;
    return 0;
}