#include <bits/stdc++.h>
using namespace std;


// got error in this approach.
// int maxScore(string s, int x, int y) {
//     deque <char> dq;
//     int score = 0;
//     if (y > x) {
//         for (int i=0; i<s.size(); i++) {
//             if  (s[i] != 'a' && s[i] != 'b') {
//                 dq.clear();
//             }
//             else if (s[i] == 'b' && (dq.empty() || dq.back() == 'b')) {
//                 dq.push_back('b');
//             }
//             else if (s[i] == 'b' && dq.back() == 'a') {
//                 dq.push_back('b');
//             }
//             else if (s[i] == 'a' && dq.empty()) {
//                 dq.push_back('a');
//             }
//             else if (s[i] == 'a' && dq.back() == 'b') {
//                 dq.pop_back();
//                 score += y;
//             }
//             else if (s[i] == 'a' && dq.back() == 'a') {
//                 dq.push_back('a');
//             }
//         }
//     } else {
//         for (int i=0; i<s.size(); i++) {
//             if  (s[i] != 'b' && s[i] != 'a') {
//                 dq.clear();
//             }
//             else if (s[i] == 'a' && (dq.empty() || dq.back() == 'a')) {
//                 dq.push_back('a');
//             }
//             else if (s[i] == 'a' && dq.back() == 'b') {
//                 dq.push_back('a');
//             }
//             else if (s[i] == 'b' && dq.empty()) {
//                 dq.push_back('b');
//             }
//             else if (s[i] == 'b' && dq.back() == 'a') {
//                 dq.pop_back();
//                 score += x;
//             }
//             else if (s[i] == 'b' && dq.back() == 'b') {
//                 dq.push_back('b');
//             }
//         }
//     }
//     while (!dq.empty()) {
//         char two = dq.back();
//         dq.pop_back();
//         if (dq.empty()) break;
//         char one = dq.back();
//         dq.pop_back();
//         if (one == 'b' && two == 'a') score += y;
//         else if (one == 'a' && two == 'b') score += x;
//     }
//     return score;
// }

int maxScore(string s, int x, int y) {
    int score = 0;
    int top_score, bot_score;
    string top, bot;
    if (x > y) {
        top = "ab";
        bot = "ba";
        top_score = x;
        bot_score = y;
    } else {
        top = "ba";
        bot = "ab";
        top_score = y;
        top_score = x;
    }
    // checking for top
    vector <char> st;
    for (char c : s) {
        if (c == top[1] && !st.empty() && st.back() == top[0]) {
            st.pop_back();
            score += top_score;
        } else {
            st.push_back(c);
        }
    }
    vector <char> stak;
    for (char c: st) {
        if (c == bot[1] && !stak.empty() && stak.back() == bot[0]) {
            stak.pop_back();
            score += bot_score;
        } else {
            stak.push_back(c);
        }
    }
    return score;
}

int main() {
    string s = "aabbaaxybbaabb";
    cout << maxScore(s, 5, 4) << endl;
    return 0;
}