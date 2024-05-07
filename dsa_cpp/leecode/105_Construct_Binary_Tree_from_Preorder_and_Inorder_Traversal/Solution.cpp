//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/6.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
            return nullptr;
        }
        
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, indexMap);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& indexMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int rootIndexInorder = indexMap[rootVal];
        int leftSubtreeSize = rootIndexInorder - inStart;
        
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndexInorder - 1, indexMap);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndexInorder + 1, inEnd, indexMap);
        
        return root;
    }
};
// Helper function to print the tree (pre-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution s;

    // Test case 1
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = s.buildTree(preorder1, inorder1);
    cout << "Test case 1:\n";
    printTree(root1);
    cout << endl;

    // Test case 2
    vector<int> preorder2 = {1, 2, 3};
    vector<int> inorder2 = {3, 2, 1};
    TreeNode* root2 = s.buildTree(preorder2, inorder2);
    cout << "\nTest case 2:\n";
    printTree(root2);
    cout << endl;

    return 0;
}
