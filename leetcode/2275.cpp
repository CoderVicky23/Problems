#include <bits/stdc++.h>
using namespace std;

int largestCombination(vector<int>& arr) {
    int n = arr.size();
    vector<int> counter (24, 0);
    int result = 0;
    for (int i=0; i<24; i++) {
        for (int& num: arr) {
            if ((num & (1 << i)) != 0) {
                counter[i]++;
            }
        }
        result = max(result, counter[i]);
    }
    return result;
}

int main(){
    vector <int> arr = {16, 17, 71, 62, 12, 24, 14};
    cout << largestCombination(arr) << endl;
    return 0;
}