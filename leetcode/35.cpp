#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int high = n-1;
    int low = 0;
    int mid = low + (high-low)/2;
    while (low < high)  {
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            high = mid - 1;
            mid = low + (high - low) / 2;
        } else {
            low = mid + 1;
            mid = low + (high - low) / 2;
        }
    }
    if (nums[mid] >= target) return mid;
    else return mid+1;
}

int main() {
    vector <int> nums = {1,3,5,6};
    int target = 5;
    cout << searchInsert(nums, target) << endl;
    return 0;
}