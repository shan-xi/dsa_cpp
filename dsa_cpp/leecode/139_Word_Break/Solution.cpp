//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/7.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << boolalpha << solution.wordBreak(s, wordDict) << endl; // Output: true
    return 0;
}
