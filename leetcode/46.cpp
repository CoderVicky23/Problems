#include <bits/stdc++.h>
using namespace std;

void fun(vector <vector <int>>& res, vector <int>& ds, int hash[], vector <int>& nums) {
    if (ds.size() == nums.size()) {
        res.push_back(ds);
        return;
    }
    for (int i=0; i<nums.size(); i++) {
        if (!hash[i]) {
            ds.push_back(nums[i]);
            hash[i] = 1;
            fun(res, ds, hash, nums);
            ds.pop_back();
            hash[i] = 0;
        }
    }
}

vector <vector <int>> permute(vector <int>& nums) {
    vector <vector <int>> result;
    vector <int> ds;
    int hash[nums.size()] = {0};
    fun(result, ds, hash, nums);
    return result;
}

// swapping the positions

void foo(vector <int>& nums, vector <vector <int>>& result, int ind, vector <int>& ds) {
    if (ind == nums.size()) {
        result.push_back(ds);
        return;
    }
    for (int i=ind; i<nums.size(); i++) {
        swap(ds[i], ds[ind]);
        foo(nums, result, ind+1, ds);
        swap(ds[i], ds[ind]);
    }
}

vector <vector <int>> swapPermute(vector <int>& nums) {
    vector <vector <int>> result;
    vector <int> ds (nums);
    foo(nums, result, 0, ds);
    return result;
}

int main() {
    vector <int> nums = {1,2,3};
    vector <vector <int>> result = swapPermute(nums);
    // cout << result.size() << endl;
    for (auto i: result) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}