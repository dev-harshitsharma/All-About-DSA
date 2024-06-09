#include <bits/stdc++.h> 
bool solution(int index, int k, vector<int> &arr, vector<vector<int>> &dp) {
    // Base case
    if (k == 0) return true;
    if (index == 0) return (arr[0] == k);

    if (dp[index][k] != -1) return dp[index][k];

    bool notTake = solution(index - 1, k, arr, dp);

    bool take = false;
    if (k >= arr[index]) {
        take = solution(index - 1, k - arr[index], arr, dp);
    }

    return dp[index][k] = take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solution(n - 1, k, arr, dp);
}
