#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c) {
    string result = "";
    priority_queue <pair <int, char>> pq;
    pq.push({a, 'a'});
    pq.push({b, 'b'});
    pq.push({c, 'c'});
    while (!pq.empty()) {
        int n = pq.top().first;
        int ch = pq.top().second;
        int len = result.size();
        pq.pop();
        if (len > 1 && (result[len-1] == ch) && (result[len-2] == c)) {
            int n2 = pq.top().first;
            int c2 = pq.top().second;
            result += c2;
            n2--;
            pq.pop();
            if (n2 > 0) pq.push({n2, c2});
        } else {
            result += ch;
            n--;
        }
        if (n > 0) pq.push({n, ch});
    }
    return result;
}

int main() {
    cout << longestDiverseString(1, 1, 7) << endl;
    return 0;
}


string longestDiverseString2(int a, int b, int c) {
    string result = "";
    priority_queue<pair<int, char>> pq;
    
    if (a > 0) pq.push({a, 'a'});
    if (b > 0) pq.push({b, 'b'});
    if (c > 0) pq.push({c, 'c'});

    while (!pq.empty()) {
        auto [n, ch] = pq.top();  // Extract top element
        pq.pop();

        // Check if adding this character will result in 3 consecutive same characters
        int len = result.size();
        if (len >= 2 && result[len - 1] == ch && result[len - 2] == ch) {
            if (pq.empty()) break;  // If no other character available, exit loop

            auto [n2, ch2] = pq.top();  // Extract second top element
            pq.pop();

            result += ch2;
            n2--;

            if (n2 > 0) pq.push({n2, ch2});
            pq.push({n, ch});  // Push back the original top element
        } else {
            result += ch;
            n--;
            if (n > 0) pq.push({n, ch});
        }
    }

    return result;
}