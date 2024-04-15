//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/14.
//

#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
    
    bool isValidBST(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (node == nullptr) return true;
        
        if ((min != nullptr && node->val <= min->val) || (max != nullptr && node->val >= max->val)) {
            return false;
        }
        
        return isValidBST(node->left, min, node) && isValidBST(node->right, node, max);
    }
};

//int main() {
//    Solution s;
//
//    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
//    cout << std::boolalpha << s.isValidBST(root) << endl; // true
//
//    root = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
//    cout << std::boolalpha << s.isValidBST(root) << endl; // false
//
//    return 0;
//}

