#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> restoreMatrix(vector <int> rowSum, vector <int> colSum) {
    int n = rowSum.size();
    int m = colSum.size();
    vector <vector <int>> matrix;
    for (int i=0; i<n; i++) {
        matrix.push_back({});
        for (int j=0; j<m; j++) {
            int k = min(rowSum[i], colSum[j]);
            matrix[i].push_back(k);
            rowSum[i] = rowSum[i] - k;
            colSum[j] = colSum[j] - k;
        }
    }
    return matrix;
}

int main() {
    vector <int> rowSum = { 5, 7, 10};
    vector <int> colSum = { 8, 6, 8};
    for (auto i: restoreMatrix(rowSum, colSum)) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}