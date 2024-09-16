#include<bits/stdc++.h>
using namespace std;

int minDif(vector <string>& timePoints) {
    set <int> st;
    for (string s: timePoints) {
        int hrs = (s[0]-48)*10 + (s[1]-48);
        int mns = (s[3]-48)*10 + (s[4]-48);
        int v = hrs*60 + mns;
        if (st.find(v) == st.end()) st.insert(v);
        else return 0;
    }
    int res = INT_MAX;
    auto itr = st.begin();
    itr++;
    for (; itr != st.end(); itr++) {
        auto a = itr;
        int dif = abs(*a - *(--a));
        res = min(res, dif);
    }
    itr = st.end();
    int k = 1440 - (*(--itr)) + (*(st.begin()));
    return min(res, k);
}

int main()
{
    vector <string> timePoints = {"00:00","04:00","22:00"};
    cout << minDif(timePoints) << endl;
    return 0;
}