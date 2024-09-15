#include<bits/stdc++.h>

using namespace std;
vector <int> xorQueries(vector <int>& arr, vector <vector <int>>& queries) {
    int n = arr.size();
    vector <int> result;
    unordered_map <int, int> hash;
    int xor_total = 0;
    for (int i=0; i<n; i++) {
        xor_total ^= arr[i];
        hash[i] = xor_total;
    }
    for (auto i: queries) {
        int a = i[0];
        int b = i[1];
        if (a == b) result.push_back(arr[a]);
        else {
            if (a == 0) result.push_back(hash[b]);
            else result.push_back(hash[b]^hash[a-1]);
        }
    }
    return result;
}
int main()
{
    vector <int> arr = {1,3,4,8};
    vector <vector <int>> queries = {{0,1},{1,2},{0,3},{3,3}};
    // xorQueries(arr, queries);
    for (int i:xorQueries(arr, queries)) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}