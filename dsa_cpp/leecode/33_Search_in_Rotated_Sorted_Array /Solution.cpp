//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/13.
//


#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[left] <= nums[mid]) {
                // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    // Target is in the left sorted side
                    right = mid - 1;
                } else {
                    // Target is in the right side
                    left = mid + 1;
                }
            } else {
                // Right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    // Target is in the right sorted side
                    left = mid + 1;
                } else {
                    // Target is in the left side
                    right = mid - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Create a vector of integers
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Define the target element to search for
    int target = 0;

    // Call the search function and print the result
    int result = solution.search(nums, target);
    std::cout << "Index of target element: " << result << std::endl;
    
    
    // Create a vector of integers
    nums = {4,5,6,7,0,1,2};

    // Define the target element to search for
    target = 3;

    // Call the search function and print the result
    result = solution.search(nums, target);
    std::cout << "Index of target element: " << result << std::endl;
    
    
    // Create a vector of integers
    nums = {1};

    // Define the target element to search for
    target = 0;

    // Call the search function and print the result
    result = solution.search(nums, target);
    std::cout << "Index of target element: " << result << std::endl;

    return 0;
}
