#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int,int>>

int minimumTime(vector<vector<int>>&grid) {

    int m = grid.size();
    int n = grid[0].size();

    vector <pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    priority_queue <P, vector <P>, greater<P>> pq;
    vector <vector <int>> result (m, vector<int>(n, INT_MAX));
    pq.push({0, {0,0}});
    result[0][0] = 0;
    
    vector<vector<int>> visited (m, vector<int> (n, false));

    while (!pq.empty()) {
        int time = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (row == m-1 && col == n-1) return result[row][col];

        if (visited[row][col] == true) continue;

        visited[row][col] = true;

        for (auto& dir: directions) {
            int i = row + dir.first;
            int j = col + dir.second;
            if (i < 0 || j < 0 || i >= m || j >= n) continue;

            if (grid[i][j] <= time + 1) {
                pq.push({time+1, {i, j}});
                result[i][j] = time + 1;
            } else if ((grid[i][j] - time)%2 == 0) {
                pq.push({grid[i][j] + 1, {i, j}});
                result[i][j] = grid[i][j]+1;
            } else {
                pq.push({grid[i][j], {i, j}});
                result[i][j] = grid[i][j];
            }
        }
    }
    return result[m-1][n-1];
}

int main(){
    vector <vector<int>> grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}};
    cout << minimumTime(grid) << endl;
    return 0;
}