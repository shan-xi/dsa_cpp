//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/15.
//

#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> stack;
        unordered_set<string> skip = {"..", ".", ""};
        
        while (getline(ss, token, '/')) {
            if (token == ".." && !stack.empty()) {
                stack.pop();
            } else if (!skip.count(token)) {
                stack.push(token);
            }
        }
        
        vector<string> result;
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        
        string simplifiedPath;
        for (int i = static_cast<int>(result.size()) - 1; i >= 0; i--) {
            simplifiedPath += "/" + result[i];
        }
        
        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};
//int main() {
//    Solution s;
//
//    cout << s.simplifyPath("/home/") << endl; // /home
//    cout << s.simplifyPath("/../") << endl; // /
//    cout << s.simplifyPath("/home//foo/") << endl; // /home/foo
//
//    return 0;
//}
