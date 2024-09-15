#include<bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal) {
    bitset <32> s(start);
    bitset <32> g(goal);
    string st = s.to_string();
    string go = g.to_string();
    int count = 0;
    for (int i=0; i<st.size(); i++) {
        if (st[i] != go[i]) {
            count++;
        }
    }
    return count;
}
int main()
{
    int start = 3;
    int goal = 4;
    cout << minBitFlips(start, goal) << endl;
    return 0;
}