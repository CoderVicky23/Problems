#include <bits/stdc++.h>
using namespace std;

int toNum(const char * s) {
    return *s - '0';
}

string countAtoms(string str) {
    int n = str.size();
    stack <unordered_map <string, int>> hash;
    hash.push({});
    int i = 0;
    while (i < n) {
        if (str[i] == '(') {
            hash.push({});
            i++;
        }
        else if (str[i] == ')') {
            unordered_map <string, int> current_map = hash.top();
            hash.pop();
            int count = 0;
            i++;
            while (i < n && isdigit(str[i])) {
                count *= 10;
                count += toNum(&str[i]);
                i++;
            }
            count = (count) ? count : 1;
            unordered_map <string, int> &prev_map = hash.top();
            for (auto &z: current_map) {
                prev_map[z.first] += z.second * count;
            }
        }
        else {
            string element = "";
            element += str[i];
            i++;
            int count = 0;
            if (i + 1 < n && islower(str[i])) {
                element += str[i];
                i++;
            }
            while (i < n && isdigit(str[i])) {
                count *= 10;
                count += toNum(&str[i]);
                i++;
            }
            count = (count) ? count : 1;
            unordered_map <string, int>& x = hash.top();
            x[element] += count;
        }
    }
    unordered_map <string, int> &current_map = hash.top();
    map <string, int> nee = {current_map.begin(), current_map.end()};
    string result = "";
    for (auto i: nee) {
        result += i.first + ((i.second == 1) ? "" : to_string(i.second));
    }
    return result;
}

int main() {
    // string str = "K4(ON(SO3)2)2";
    string str = "H20";
    cout << countAtoms(str) << endl;
    return 0;
}