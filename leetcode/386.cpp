#include<bits/stdc++.h>
using namespace std;

void dfs(int n, int i, vector <int>& result) {
    if (i > n) return;
    result.push_back(i);
    i *= 10;
    for (int j=0; j<10; j++) {
        if (j > n) break;
        dfs(n, i+j, result);
    }
}

vector <int> lexicalOrder(int n) {
    vector <int> result;
    for (int i=1; i<10; i++) {
        dfs(n, i, result);
    }
    return result;
}

int main()
{
    int n = 340;
    cout << lexicalOrder(n).size() << endl;
    // for (int i: lexicalOrder(n)) {
    //     cout << i << " ";
    // }
    // cout << endl;
    return 0;
}