//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/27.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // Swap the values of the two out-of-order nodes
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        inorder(root->left);
        
        // Check if previous node is greater than current node
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        
        prev = root;
        
        inorder(root->right);
    }
};
