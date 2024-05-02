//
//  Solution.cpp
//  dsa_cpp
//
//  Created by 廖善璽 on 2024/5/1.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Fill the rest of the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
//int main(){
//    Solution s;
//    
//    cout << s.uniquePaths(3, 7) << endl; // Output: 28
//    cout << s.uniquePaths(3, 2) << endl; // Output: 3
//
//    return 0;
//}
