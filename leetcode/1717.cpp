#include <bits/stdc++.h>
using namespace std;

int fun(string s, int x, int y, char a, char b) {
    deque <char> dq;
    int score = 0;
    for (int i=0; i < s.size(); i++) {
        if (s[i] == a && dq.back() == b) {
            score += y;
            dq.pop_back();
        } 
        else if (s[i] == a) dq.push_back(a);
        else if (s[i] == b && dq.back() == a) ;
    }
}

int maxScore(string s, int x, int y) {
    deque <char> dq;
    int score = 0;
    // assuming taking y as priority
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'a' && dq.back() == 'b') {
            score += y;
            dq.pop_back();
        }
        else if (s[i] == 'a') dq.push_back('a');
        else if (s[i] == 'b' && dq.back() == 'a') {
            
        }
    }
}

int main() {
    string s = "cdbcbbaaabab";
    maxScore(s, 4, 5);
    return 0;
}