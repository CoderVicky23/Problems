#include<bits/stdc++.h>
using namespace std;

bool compare(const string& a, const string& b) {
    return (a + b > b + a);
}

string largestNumber(vector <int>& nums) {
    vector <string> numStrings;
    for (int i=0; i<nums.size(); i++) {
        numStrings.push_back(to_string(nums[i]));
    }
    sort(numStrings.begin(), numStrings.end(), compare);
    if (numStrings[0] == "0") return "0";
    string result;
    for (auto i: numStrings) {
        result += i;
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    return 0;
}