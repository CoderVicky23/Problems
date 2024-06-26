#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector <int> majorityElement(vector <int> nums) {
    int count1 = 0, count2 = 0;
    int element1 = INT_MIN, element2 = INT_MIN;
    for (int i=0; i<nums.size(); i++) {
        if (count1 == 0 && element2 != nums[i]) {
            element1 = nums[i];
            count1++;
        }
        else if (count2 == 0 && element1 != nums[i]) {
            element2 = nums[i];
            count2++;
        }
        else if (nums[i] == element1) {
            count1++;
        }
        else if (nums[i] == element2) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for (int i=0; i<nums.size(); i++) {
        if (element1 == nums[i]) count1++;
        if (element2 == nums[i]) count2++;
    }
    int a = (nums.size())/3;
    if (count1 > a && count2 > a) return {element1, element2};
    else if (count1 > a) return {element1};
    else if (count2 > a) return {element2};
    else return {};
}

int main() {
    vector <int> array = {2, 1, 1, 2, 1, 2, 5, 6};
    vector <int> result = majorityElement(array);
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}