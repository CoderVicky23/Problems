#include <iostream>
#include <vector>
using namespace std;

void fun(vector <int>& nums, int total_sum, int partial_sum, bool& flag, int ind) {
    if (flag) return;
    if (total_sum - partial_sum == partial_sum) {
        flag = 1;
        return;
    }
    if (ind == nums.size()) return;
    fun(nums, total_sum, partial_sum + nums[ind], flag, ind+1);
    fun(nums, total_sum, partial_sum, flag, ind+1);
}

bool canPartition(vector <int>& nums) {
    int total_sum = 0;
    int partial_sum = 0;
    for (int i=0; i<nums.size(); i++) total_sum += nums[i];
    bool flag = 0;
    fun(nums, total_sum, partial_sum, flag, 0);
    return flag;
}

int main() {
    vector <int> nums = { 1, 5, 11, 5};
    cout << canPartition(nums) << endl;
    return 0;
}