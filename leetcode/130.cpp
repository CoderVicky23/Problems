#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<string>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited (n, vector<bool> (m, 0));
    queue <pair<int, int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                if (board[i][j] == "O") {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }
    int r_inds[] = {-1, 0, 1, 0};
    int c_inds[] = {0, -1, 0, 1};
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int nr = r + r_inds[i];
            int nc = c + c_inds[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == "O" && !visited[nr][nc]) {
                // cout << nr << " " << nc << endl;
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == "O" && visited[i][j] == 0) {
                board[i][j] = "X";
            }
        }
    }
}

int main(){
    // vector <vector <string>> board = {{"X","X","X","X"},{"X","O","O","X"},{"X","X","O","X"},{"X","O","X","X"}};
    vector <vector <string>> board = {{"X","O","X"},{"X","O","X"},{"X","O","X"}};
    solve(board);
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}