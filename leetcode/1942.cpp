#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& a, const vector <int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int smallestChair(vector <vector <int>>& times, int target) {
    int n = times.size();
    int target_arrival_time = times[target][0];

    sort(times.begin(), times.end(), compare);

    priority_queue <int, vector <int>, greater<int>> available;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> reserved;

    for (auto& i: times) {
        while (!reserved.empty() && reserved.top().first <= i[0]) {
            available.push(reserved.top().second);
            reserved.pop();
        }
        if (i[0] == target_arrival_time) break;
        if (available.empty()) reserved.push({i[1], reserved.size()});
        else {
            reserved.push({i[1], available.top()});
            available.pop();
        }
    }
    return available.empty() ? reserved.size() : available.top();
}

int main() {
    vector <vector <int>> times = {{1,4}, {2,3}, {4, 6}};
    int target = 1;
    int res = smallestChair(times, target);
    cout << res << endl;
    return 0;
}