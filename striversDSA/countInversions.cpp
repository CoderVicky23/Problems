#include <bits/stdc++.h>
using namespace std;

long long countInversionsBrute(vector <int> arr) {
    int n = arr.size();
    long long count = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) count++;
        }
    }
    return count;
}

long long merge(vector <int>& arr, int left, int mid, int right) {
    long long count = 0;
    vector <int> temp;
    int i = left, j = mid+1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    for (int k=left, l=0; k<=right; k++, l++) {
        arr[k] = temp[l];
    }
    return count;
}

long long mergeSort(vector <int>& arr, int left, int right) {
    long long count = 0;
    if (left >= right) return count;
    int mid = left + (right - left) / 2;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid+1, right);
    count += merge(arr, left, mid, right);
    return count;
}

long long countInversions(vector <int> arr) {
    return mergeSort(arr, 0, arr.size()-1);
}

int main() {
    vector <int> arr = {2, 4, 1, 3, 5};
    cout << countInversions(arr) << endl;
    return 0;
}