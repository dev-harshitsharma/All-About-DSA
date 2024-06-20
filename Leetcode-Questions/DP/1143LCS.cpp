class Solution {
public:
    int solve( int index1 , int index2,string text1,string text2,vector<vector<int>> dp){
        if( index1 < 0 || index2 < 0){
            return 0;
        }
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + solve(index1-1,index2-1,text1,text2,dp);   
        }

        return dp[index1][index2] = max(solve(index1-1,index2,text1,text2,dp),solve(index1,index2-1,text1,text2,dp)); 
    }
   int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};