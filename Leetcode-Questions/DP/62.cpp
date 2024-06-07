class Solution {
public: 

    //Memoized solution 
    int solution (int i , int j , vector<vector<int>>& dp){
        if( i == 0 && j==0) return 1;
        if(i < 0 || j< 0)  return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solution(i-1,j,dp);
        int left = solution(i,j-1,dp);

        return dp[i][j] = up+left ;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solution (m-1,n-1,dp);

        // Space optimized solution after tabulation 
        vector<int> prev(n,0);
        for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
        return prev[n-1];
    }
};