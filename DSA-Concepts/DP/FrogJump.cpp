#include <bits/stdc++.h>
using namespace std;

int func(int index, vector<int> &heights, vector<int> &dp) {
    if (index == 0) return 0;
    if (dp[index] != -1) return dp[index];
    
    int left = func(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int right = INT_MAX; 
    if (index > 1) {
        right = func(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n, -1); 
    return func(n - 1, heights, dp);
}
