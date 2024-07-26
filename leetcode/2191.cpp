#include <bits/stdc++.h>
using namespace std;

vector <int> sortJumbled(vector <int>& mapping, vector <int>& nums) {
    vector <int> conversion;
    map <int, vector <int>> hash;
    for (int i=0; i<nums.size(); i++) {
        int newNum = 0;
        int k = nums[i];
        int rem = 0;
        int m = 0;
        while (k > 0) {
            rem = k%10;
            newNum = newNum + mapping[rem]*round(pow(10,m++));
            k = k/10;
        }
        cout << newNum << endl;
        if (hash.find(newNum) != hash.end()) {
            hash[newNum].push_back(nums[i]);
        } else {
            hash[newNum] = {nums[i]};
        }
    }
    for (auto i: hash) {
        for (int j=0; j<i.second.size(); j++) {
            conversion.push_back(i.second[j]);
        }
    }
    return conversion;
}

int main() {
    vector <int> mapping = {9,8,7,6,5,4,3,2,1,0};
    vector <int> nums = {0,1,2,3,4,5,6,7,8,9};
    vector <int> result = sortJumbled(mapping, nums);
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}