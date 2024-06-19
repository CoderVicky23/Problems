// maximum sub array sum

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int maxSubSum(int * arr, int n) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int i=0; i<n; i++) {
        sum += arr[i];
        maxi = (maxi > sum) ? maxi : sum;
        if (sum < 0) sum = 0;
    }
    return maxi;
}

// in case we need to return the indexes of the largest sub arrays
vector<int> maxSubSumArr(int  * arr, int n) {
    int sum = 0;
    int maxi = INT_MIN;
    int start = -1;
    int arrStart, arrEnd;
    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // collect the starting index whenever sum = 0
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            arrStart = start; // whenever you hit a max, set the arrStart and arrEnd
            arrEnd = i;
        }
        if (sum < 0) sum = 0;
    }
    return {maxi, arrStart, arrEnd};
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(int);
    // int result = maxSubSum(arr, n);
    vector <int> result = maxSubSumArr(arr, n);
    for (int i: result) {
        cout << i << endl;
    }
    return 0;
}