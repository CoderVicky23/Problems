#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int K;
    priority_queue <int, vector <int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop(); // poping minimum element
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    int k = 3;
    vector <int> nums = {4, 5, 8, 2};
    vector <int> inputs = {3, 5, 10, 9, 4};
    KthLargest * obj = new KthLargest(k, nums);
    for (int i: inputs) {
        cout << obj->add(i) << " ";
    }
    cout << endl;
    return 0;
}