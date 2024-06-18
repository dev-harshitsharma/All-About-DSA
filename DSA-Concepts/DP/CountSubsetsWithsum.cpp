int solution(int index, vector<int>& arr, int target, vector<vector<int>>& dp) {
    if (target == 0) return 1;
    if (index == 0) return (arr[0] == target);

    if (dp[index][target] != -1) return dp[index][target];

    int notTake = solution(index - 1, arr, target, dp);
    int take = 0;
    if (arr[index] <= target) take = solution(index - 1, arr, target - arr[index], dp);

    return dp[index][target] = take + notTake;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    // Base case: There is one way to form the sum 0 (by selecting no elements)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Base case: If the first element is less than or equal to the target,
    // then there's one way to form the target by using the first element
    if (arr[0]<=k) {
        dp[0][arr[0]] = 1;
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            int notTake = dp[i-1][target]; // ways to form the target without current element
            int take = 0;
            if (arr[i] <= target) {
                take = dp[i-1][target - arr[i]]; // ways to form the target with current element
            }
            dp[i][target] = take + notTake; // total ways to form the target
        }
    }

    return dp[n-1][k]; // The answer is the number of ways to form sum k using all elements
}
 