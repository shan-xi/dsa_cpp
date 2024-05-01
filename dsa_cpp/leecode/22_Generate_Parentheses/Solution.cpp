//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/4/27.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, 0, n);
        return result;
    }
    
    void generate(vector<string>& result, string current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }
        
        if (open < max) {
            generate(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            generate(result, current + ")", open, close + 1, max);
        }
    }
};

//int main(){
//    Solution s;
//
//    vector<string> result1 = s.generateParenthesis(3);
//    cout << "[";
//    for (int i = 0; i < result1.size(); i++) {
//        cout << "\"" << result1[i] << "\"";
//        if (i < result1.size() - 1) cout << ",";
//    }
//    cout << "]" << endl;
//
//    vector<string> result2 = s.generateParenthesis(1);
//    cout << "[";
//    for (int i = 0; i < result2.size(); i++) {
//        cout << "\"" << result2[i] << "\"";
//        if (i < result2.size() - 1) cout << ",";
//    }
//    cout << "]" << endl;
//
//    return 0;
//}
