#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subArraySum(vector <int>& nums, int k) {
    unordered_map <int, int> hash;
    int prefix = 0;
    int count = 0;
    hash[prefix] = 1;
    for (int i=0; i<nums.size(); i++) {
        prefix += nums[i];
        int rem = prefix - k;
        count += hash[rem];
        hash[prefix]++;
    }
    return count;
}

int main() {
    vector <int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    cout << subArraySum(nums, k);
    return 0;
}