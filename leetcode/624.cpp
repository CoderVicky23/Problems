#include<bits/stdc++.h>

using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int result = 0;
    int cur_min = arrays[0][0];
    int cur_max = arrays[0][arrays[0].size()-1];
    for (int i = 1; i < arrays.size(); i++) {
        vector <int> a = arrays[i];
        result = max(result, max(cur_max-a[0], a[a.size()-1]-cur_min));
        cur_max = max(cur_max, a[a.size()-1]);
        cur_min = min(cur_min, a[0]);
        cout << "current max: " << cur_max << " current min: " << cur_min << " result : " << result << endl;
    }
    return result;
}

int main()
{
    vector <vector <int>> arrays = {{-8,-7,-7,-5,1,1,3,4},{-2},{-10,-10,-7,0,1,3},{2}};
    cout << maxDistance(arrays) << endl;
    return 0;
}