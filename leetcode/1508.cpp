#include<bits/stdc++.h>

using namespace std;

int rangeSum(vector <int>& nums, int n, int left, int right) {
    vector <int> sumResult;
    int _sum = 0;
    int mod = 1000000007;
    int result = 0;
    for (int i=0; i<n; i++) {
        _sum = 0;
        for (int j=i; j<n; j++) {
            _sum += nums[j];
            sumResult.push_back(_sum);
        }
    }
    sort(sumResult.begin(), sumResult.end());
    for (int i=left-1; i<right; i++) {
        result = (result + sumResult[i])%mod;
    }
    return result;
}

int main()
{
    vector <int> nums = {1,2,3,4};
    int n = 4, left = 1, right = 5;
    cout << rangeSum(nums, n, left, right) << endl;
    return 0;
}