#include<bits/stdc++.h>

using namespace std;

int secondsToRemoveOccurrences(string s) {
    int n = s.size();
    bool flag = 0;
    int count = 0;
    while (1) {
        flag = 0;
        for (int i=0; i<n-1; i++) {
            if (s[i] == '0' && s[i+1] == '1') {
                swap(s[i], s[i+1]);
                flag = 1;
                i++;
            }
        }
        if (flag == 0) break;
        count++;
    }
    return count;
}

int main()
{
    string s = "0000011";
    cout << secondsToRemoveOccurrences(s) << endl;
    return 0;
}