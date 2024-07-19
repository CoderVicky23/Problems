#include <bits/stdc++.h>
using namespace std;

int foo(vector <int> nums) {
    int n = nums.size();
    int r = 0;
    long long sum = 0;
    int maxi = 0;
    unordered_map <int, int> hash;
    hash[0] = -1;
    while (r < n) {
        sum += (long long) nums[r];
        if (hash.find(sum) == hash.end()) {
            hash[sum] = r;
        } else {
            maxi = max(maxi, r - hash[sum]);
        }
        r++;
    }
    return maxi;
}

int main() {
    vector <int> nums = {1, -1, 1, -1}; // {2, 10, 4}; // {15,-2,2,-8,1,7,10,23};
    cout << foo(nums) << endl;
    return 0;
}