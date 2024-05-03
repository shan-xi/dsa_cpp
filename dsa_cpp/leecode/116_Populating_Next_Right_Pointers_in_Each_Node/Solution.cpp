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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if (i < size - 1) {
                    node->next = q.front();
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return root;
    }
};

// Function to print the next pointers of each node
void printNextPointers(Node* root) {
    if (!root) return;
    
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        while (current) {
            cout << current->val;
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
        levelStart = levelStart->left;
    }
}
