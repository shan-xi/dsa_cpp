//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/2.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = static_cast<int>(nums.size()) - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = static_cast<int>(nums.size()) - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

//int main() {
//    Solution s;
//    vector<int> d1 = {1, 2, 3};
//    s.nextPermutation(d1);
//    cout << "[ ";
//    for (int num : d1) {
//        cout << num << " ";
//    }
//    cout << "]" << endl; // 1 3 2
//
//    vector<int> d2 = {3, 2, 1};
//    s.nextPermutation(d2);
//    cout << "[ ";
//    for (int num : d2) {
//        cout << num << " ";
//    }
//    cout << "]" << endl; // 1 2 3
//
//    vector<int> d3 = {1, 1, 5};
//    s.nextPermutation(d3);
//    cout << "[ ";
//    for (int num : d3) {
//        cout << num << " ";
//    }
//    cout << "]" << endl; // 1 5 1
//
//    return 0;
//}
