#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        int minFreq = INT_MAX, maxFreq = 0;
        for (auto& p : freq) {
            minFreq = min(minFreq, p.second);
            maxFreq = max(maxFreq, p.second);
        }
        
        if (minFreq == maxFreq) return 0;
        
        int minOperations = INT_MAX;
        
        for (int targetFreq = minFreq; targetFreq <= maxFreq; targetFreq++) {
            int currOperations = 0;
            for (auto& p : freq) {
                if (p.second > targetFreq) {
                    currOperations += p.second - targetFreq;
                } else if (p.second < targetFreq) {
                    currOperations += targetFreq - p.second;
                }
            }
            minOperations = min(minOperations, currOperations);
        }
        
        return minOperations;
    }
};

// Test function to run multiple test cases
void runTestCases() {
    Solution solution;
    
    // Test Case 1
    string s1 = "aaabc";
    cout << "Test Case 1: s = " << s1 << ", Output = " 
         << solution.minOperations(s1) << " (Expected: 2)" << endl;
    
    // Test Case 2
    string s2 = "wddw";
    cout << "Test Case 2: s = " << s2 << ", Output = " 
         << solution.minOperations(s2) << " (Expected: 0)" << endl;
    
    // Test Case 3
    string s3 = "acab";
    cout << "Test Case 3: s = " << s3 << ", Output = " 
         << solution.minOperations(s3) << " (Expected: 1)" << endl;
}

int main() {
    runTestCases();
    return 0;
}