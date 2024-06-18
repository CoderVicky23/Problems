#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// using prefix sum approach (valid for positives, negatives and zeros)
int fun(vector <int> a, long long k) {
    unordered_map <long long, int> count;
    int n = a.size();
    int maxi = 0;
    long long prefix_sum = 0;
    for (int i=0; i<n; i++) {
        prefix_sum += a[i];
        if (prefix_sum == k) {
            maxi = max(maxi, i+1);
        }
        long long rem = prefix_sum - k;
        if (count.find(rem) != count.end()) {
            int len = i - count[rem];
            maxi = max(maxi, len);
        }
        if (count.find(prefix_sum) == count.end()) {
            count[prefix_sum] = i;
        }
    }
    return maxi;
}

// using 2 pointers method (valid for only positives and zeros)
int foo(vector <int> a, long long k) {
    int left = 0, right = 0;
    int sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}

int main() {
    int k = 4;
    vector<int> a = {1, 2, 3, 1, 2, 1, 3, 1, 1, 1};
    cout << fun(a, k) << endl;
    return 0;
}