//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/14.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move fast to the end, maintaining the gap of n between fast and slow pointers
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};

vector<int> travelAllNodes(ListNode* root) {
    vector<int> r;
    if (root == nullptr) return r;
    r.push_back(root->val);
    while (root->next != nullptr) {
        root = root->next;
        r.push_back(root->val);
    }
    return r;
}

int main() {
    Solution s;

    // Test cases
    ListNode* root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* res = s.removeNthFromEnd(root, 2); // [1,2,3,5]
    vector<int> result1 = travelAllNodes(res);
    cout << "[";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    root = new ListNode(1);
    res = s.removeNthFromEnd(root, 1); // []
    vector<int> result2 = travelAllNodes(res);
    cout << "[";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    root = new ListNode(1, new ListNode(2));
    res = s.removeNthFromEnd(root, 1); // [1]
    vector<int> result3 = travelAllNodes(res);
    cout << "[";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
