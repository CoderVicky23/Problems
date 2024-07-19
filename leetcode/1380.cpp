#include <bits/stdc++.h>
using namespace std;

// brute force method
vector <int> luckyNumbers(vector <vector <int>> matrix) {
    vector <int> row_mins;
    for (int i=0; i<matrix.size(); i++) {
        int row_min = INT_MAX;
        for (int j=0; j<matrix[i].size(); j++) {
            row_min = min(row_min, matrix[i][j]);
        }
        row_mins.push_back(row_min);
    }
    vector <int> col_maxs;
    for (int i=0; i<matrix[0].size(); i++) {
        int col_max = INT_MIN;
        for (int j=0; j<matrix.size(); j++) {
            col_max = max(col_max, matrix[j][i]);
        }
        col_maxs.push_back(col_max);
    }
    vector <int> result;
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j] == col_maxs[j] && matrix[i][j] == row_mins[i]) {
                result.push_back(matrix[i][j]);
            }
        }
    }
    return result;
}


int main() {
    vector <vector <int>> matrix = {{3,6}, {7, 1}, {5, 2}, {4, 8}};
    for (auto i: luckyNumbers(matrix)) {
        cout << i << " ";
    } cout << endl;
    return 0;
}