//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/6.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() <= 10) {
            return result;
        }
        
        unordered_map<string, int> map;
        
        for (int i = 0; i <= s.length() - 10; i++) {
            string sequence = s.substr(i, 10);
            map[sequence]++;
            if (map[sequence] == 2) {
                result.push_back(sequence);
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<string> res1 = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (const auto& seq : res1) {
        cout << seq << " ";
    }
    cout << endl; // ["AAAAACCCCC","CCCCCAAAAA"]

    vector<string> res2 = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    for (const auto& seq : res2) {
        cout << seq << " ";
    }
    cout << endl; // ["AAAAAAAAAA"]

    return 0;
}
