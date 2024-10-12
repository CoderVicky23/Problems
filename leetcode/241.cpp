#include<bits/stdc++.h>

using namespace std;

class Solution {

    public:
    int add(int a, int b) { return a + b; }
    int sub(int a, int b) { return a - b; }
    int mul(int a, int b) { return a * b; }
    vector <int> backtrack(string expression, int left, int right) {
        vector <int> result;
        for (int i=left; i<=right; i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                vector <int> nums1 = backtrack(expression, left, i-1);
                vector <int> nums2 = backtrack(expression, i+1, right);
                for (int j: nums1) {
                    for (int k: nums2) {
                        if (c == '+') {
                            result.push_back(add(j, k));
                        } else if (c == '*') {
                            result.push_back(mul(j, k));
                        } else if (c == '-') {
                            result.push_back(sub(j, k));
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            int n = 0;
            for (int i=left; i<=right; i++) {
                n *= 10;
                n += expression[i]-48;
            }
            return {n};
        }
        return result;
    }
    vector <int> diffWaysToCompute(string expression) {
        return backtrack(expression, 0, expression.size()-1);
    }
};


int main()
{
    string  expression = "2*3-4*5";
    Solution * obj = new Solution();
    for (auto i: obj->diffWaysToCompute(expression)) {
        cout << i << endl;
    }
    return 0;
}