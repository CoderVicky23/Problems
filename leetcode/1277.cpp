#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int count = 0;
    vector <vector <int>> dp (m, vector <int> (n, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (i == 0 || j == 0) {
                if (matrix[i][j]) {
                    dp[i][j] = 1;
                    count++;
                }
                cout << dp[i][j] << " ";
                continue;
            }
            if (matrix[i][j] == 0) continue;
            dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
            count += dp[i][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return count;
}

int main() {
    vector <vector <int>> matrix = {
                                {0,1,1,1},
                                {1,1,1,1},
                                {0,1,1,1}
                                };
    cout << countSquares(matrix) << endl;
    return 0;
}