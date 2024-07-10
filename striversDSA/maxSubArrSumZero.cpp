#include <bits/stdc++.h>
using namespace std;

int foo(vector <int> nums) {
    int n = nums.size();
    int l = 0, r = 0;
    long long sum = 0;
    int len = 0;
    while (r < n) {
        sum += nums[r];
    }
}

int main() {
    vector <int> nums = {15,-2,2,-8,1,7,10,23};
    cout << foo(nums) << endl;
    return 0;
}