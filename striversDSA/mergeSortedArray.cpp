#include <bits/stdc++.h>
using namespace std;

void mergeVector(vector <int>& nums1, int n, vector <int>& nums2, int m) {
    int a = n-1, b = m-1, c = n+m-1;
    cout << a << " " << b << " " << c << endl;
    while (c > 0 && a >= 0 && b >= 0) {
        if (nums1[a] < nums2[b]) {
            nums1[c] = nums2[b];
            c--;
            b--;
        } else {
            swap(nums1[a], nums1[c]);
            c--;
            a--;
        }
    }
    while (b >= 0) {
        nums1[c] = nums2[b];
        c--;
        b--;
    }
    while (a >= 0) {
        swap(nums1[a], nums1[c]);
        a--;
        c--;
    }
}

int main() {
    vector <int> nums1 = {0}; //{7, 8, 15, 16, 20, 0, 0, 0, 0};
    vector <int> nums2 = {1};
    mergeVector(nums1, 0, nums2, 1);
    for (int i: nums1) {
        cout << i << endl;
    }
    return 0;
}