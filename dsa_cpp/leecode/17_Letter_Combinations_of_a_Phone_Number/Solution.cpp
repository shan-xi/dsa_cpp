//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/13.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        
        vector<string> mapping = {
            "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        backtrack(result, digits, mapping, 0, "");
        return result;
    }
    
    void backtrack(vector<string>& result, const string& digits, const vector<string>& mapping, int index, string current) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            backtrack(result, digits, mapping, index + 1, current + c);
        }
    }
};
int main() {
    Solution s;

    // Test cases
    vector<string> result1 = s.letterCombinations("23");
    cout << "[";
    for (int i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    vector<string> result2 = s.letterCombinations("");
    cout << "[";
    for (int i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    vector<string> result3 = s.letterCombinations("2");
    cout << "[";
    for (int i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
