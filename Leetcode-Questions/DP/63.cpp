class Solution {
public:
    int function(vector<vector<int>>& arr, int i, int j, vector<vector<int>>& dp) {
        // Base case: if out of bounds or obstacle encountered, return 0
        if (i < 0 || j < 0 || arr[i][j] == 1)
            return 0;
        // Base case: if at the starting point, return 1
        if (i == 0 && j == 0)
            return 1;
        // If already computed, return the stored value
        if (dp[i][j] != -1)
            return dp[i][j];
        
        // Recursively calculate the number of unique paths
        int up = function(arr, i - 1, j, dp);
        int left = function(arr, i, j - 1, dp);
        
        // Store and return the result
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // Start the recursive computation from the bottom-right corner
        return function(obstacleGrid, m - 1, n - 1, dp);
    }
};
