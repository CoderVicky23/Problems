#include<bits/stdc++.h>

using namespace std;
int winningPlayerCount(vector <vector <int>>& pick) {
    unordered_map <int, unordered_map <int, int>> hash;
    for (auto i: pick) {
        hash[i[0]][i[1]]++;
    }
    int count = 0;
    for (auto i: hash) {
        int j = i.first;
        for (auto k: i.second) {
            if (k.second > j) {
                count++;
                break;
            }
        }
    }
    return count;
}
int main()
{
    vector <vector <int>> pick = { {0,0}, {1,0}, {1,0}, {2,1}, {2,1}, {2,0}};
    cout << winningPlayerCount(pick) << endl;
    return 0;
}