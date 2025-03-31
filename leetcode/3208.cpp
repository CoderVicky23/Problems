#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& colors, int k) {
    int n = colors.size();
    int N = n+k;
    for (int i=n; i<N; i++){
        colors.push_back(colors[i-n]);
    }

    // brute force
    int result = 0;
    int i = 0;
    int j = 1;
    while (j < N) {
        if (colors[j] == colors[i]) {
            i = j;
            j++;
            continue;
        } else if (j - i + 1 == k){
            result++;
            i++;
        }
        j++;
    }
    return result;
}

int main(){
    vector <int> colors = {1, 1, 0, 1};
    int k = 4;
    cout << fun(colors, k) << endl;
    return 0;
}