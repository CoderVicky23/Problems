#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruits(int N, vector<int>& fruits) {
    unordered_map<int, int> count;
    int l=0, r=0;
    int max_len = 0;
    while (r < N) {
        count[fruits[r]]++;
        if (count.size() > 2) {
            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) count.erase(fruits[l]);
                l++;
            }
        } else {
            max_len = max(max_len, r-l+1);
        }
        r++;
    }
    return max_len;
}

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "File not open!" << endl;
        return 1;
    }
    vector<int> fruits;
    int N;
    inputFile >> N;
    int number;
    while (inputFile >> number) {
        fruits.push_back(number);
    }
    inputFile.close();
    cout << totalFruits(N, fruits) << endl;
    return 0;
}


// int totalFruits(int N, vector<int> &fruits) {
//     if (N < 3) return N;
//     int left = 0, right = 2;
//     int max_len = 2;
//     int b1 = fruits[0];
//     int b2 = fruits[1];
//     while (right < N) {
//         if (fruits[right] == b1) {
//             b1 = b2;
//             b2 = fruits[right];
//             right++;
//             max_len = max(max_len, right-left);
//         } else if (fruits[right] == b2) {
//             right++;
//             max_len = max(max_len, right-left);
//         } else {
//             b1 = b2;
//             b2 = fruits[right];
//             left++;
//             while (fruits[left] != b1) left++;
//             right++;
//             max_len = max(max_len, right-left);
//         }
//         cout << "Max_len right = " << right << " left = " << left << " => " << max_len << endl;
//     }
//     return max_len;
// }