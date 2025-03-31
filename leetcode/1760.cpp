#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums, int& maxOperations, int& mid) {
    int totalOps = 0; // to bring each number to mid
    for (int& num: nums) {
        int ops = ceil(num/mid) - 1;
        totalOps += ops;
    }
    return totalOps <= maxOperations;
}

int minimumSize(vector<int>& nums, int& maxOperations) {
    int l = 1;
    int r = *max_element(nums.begin(), nums.end());
    int result = r;
    while (l <= r) {
        int mid = l + (r - l)/2;
        if (isPossible(nums, maxOperations, mid)) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2,4,8,2};
    int maxOperations = 4;
    cout << minimumSize(nums, maxOperations) << endl;
    return 0;
}