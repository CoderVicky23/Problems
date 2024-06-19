#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print(pair <int, int> * arr, int s) {
    for (int i = 0; i < s; i++ ) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}

// using hash map
vector <int> twoSumHashMap(vector <int> nums, int target) {
    unordered_map <int, int> mp;
    int diff;
    for (int i=0; i<nums.size(); i++) {
        diff = target - nums[i];
        if (mp.find(diff) != mp.end()) {
            return { mp[diff], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// using sorting and two pointers
vector <int> twoSumSort(vector <int> nums, int target) {
    pair <int, int> * arr = new pair <int, int> [nums.size()];
    for (int i=0; i<nums.size(); i++) {
        arr[i].first = nums[i];
        arr[i].second = i;
    }
    sort(arr, arr + nums.size(), [](pair <int, int> a, pair <int, int> b) {
        return (a.first < b.first) ? true : false;
    });
    // print(arr, nums.size());
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int a = arr[left].first + arr[right].first;
        cout << a << endl;
        if (target == a) return {arr[left].second, arr[right].second};
        else if (target > a) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    vector <int> nums = {2, 15, 7, 11};
    int target = 22;
    vector <int> result = twoSumSort(nums, target);
    for (int i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}