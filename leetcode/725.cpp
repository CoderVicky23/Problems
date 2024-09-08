#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

void traversal(ListNode * h) {
    ListNode * temp = h;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector <ListNode *> splitListToParts(ListNode * head, int k) {
    if (!head) return vector <ListNode *> (k, nullptr);
    ListNode * itr = head;
    int count = 0;
    while (itr) {
        count++;
        itr = itr->next;
    }
    int div = count/k;
    int rem = count%k;
    vector <ListNode *> result (k, nullptr);
    ListNode * curr = head;
    ListNode * prev = nullptr;
    ListNode * temp = nullptr;
    ListNode * dady = nullptr;
    int ind = 0;
    if (count > k) {
        while (curr) {
            temp = new ListNode(curr->val);
            dady = temp;
            curr = curr->next;
            for (int i=1; i<div; i++) {
                prev = temp;
                temp = new ListNode(curr->val);
                prev->next = temp;
                curr = curr->next;
            }
            if (rem > 0) {
                prev = temp;
                temp = new ListNode(curr->val);
                prev->next = temp;
                curr = curr->next;
                rem--;
            }
            result[ind++] = dady;
        }
    } else {
        while (curr) {
            result[ind++] = new ListNode(curr->val);
            curr = curr->next;
        }
    }
    return result;
}

int main()
{
    ListNode * b = new ListNode(10);
    for (int i=9; i>0; i--) {
        ListNode * temp = new ListNode(i, b);
        b = temp;
    }
    ListNode * head = b;
    int k = 4;
    vector <ListNode *>output =  splitListToParts(head, k);
    for (auto i: output) {
        traversal(i);
    }
    return 0;
}