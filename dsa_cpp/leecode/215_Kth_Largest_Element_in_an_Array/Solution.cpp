//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/3.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Add elements to the min heap
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element if the size exceeds k
            }
        }
        
        // The top of the min heap will be the kth largest element
        return minHeap.top();
    }
};
//int main() {
//    Solution s;
//    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
//    cout << s.findKthLargest(nums1, 2) << endl; // 5
//    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
//    cout << s.findKthLargest(nums2, 4) << endl; // 4
//    return 0;
//}
