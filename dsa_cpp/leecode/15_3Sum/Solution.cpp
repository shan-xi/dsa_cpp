//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            
            int left = i + 1;
            int right = static_cast<int>(nums.size()) - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

//int main() {
//    Solution s;
//
//    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
//    vector<vector<int>> result1 = s.threeSum(nums1);
//    cout << "[";
//    for (int i = 0; i < result1.size(); i++) {
//        cout << "[";
//        for (int j = 0; j < result1[i].size(); j++) {
//            cout << result1[i][j];
//            if (j < result1[i].size() - 1) cout << ",";
//        }
//        cout << "]";
//        if (i < result1.size() - 1) cout << ",";
//    }
//    cout << "]" << endl; // [[-1,-1,2],[-1,0,1]]
//
//    vector<int> nums2 = {0, 1, 1};
//    vector<vector<int>> result2 = s.threeSum(nums2);
//    cout << "[";
//    for (int i = 0; i < result2.size(); i++) {
//        cout << "[";
//        for (int j = 0; j < result2[i].size(); j++) {
//            cout << result2[i][j];
//            if (j < result2[i].size() - 1) cout << ",";
//        }
//        cout << "]";
//        if (i < result2.size() - 1) cout << ",";
//    }
//    cout << "]" << endl; // []
//
//    vector<int> nums3 = {0, 0, 0};
//    vector<vector<int>> result3 = s.threeSum(nums3);
//    cout << "[";
//    for (int i = 0; i < result3.size(); i++) {
//        cout << "[";
//        for (int j = 0; j < result3[i].size(); j++) {
//            cout << result3[i][j];
//            if (j < result3[i].size() - 1) cout << ",";
//        }
//        cout << "]";
//        if (i < result3.size() - 1) cout << ",";
//    }
//    cout << "]" << endl; // [[0,0,0]]
//
//    return 0;
//}
