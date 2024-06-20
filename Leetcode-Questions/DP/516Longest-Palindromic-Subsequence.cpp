class Solution {
public:
    int lcs (string s1,string s2){
        int n =  s1.size();
        int m =  s2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for( int i = 0;i<n;i++) dp[i][0] = 0;
        for( int j =0;j<m;j++) dp[0][j] = 0;
        for( int i =1;i<=n;i++){
            for( int j=1;j<=m;j++){
                // Match 
                if(s1[i-1] == s2[j-1]){
                  dp[i][j] = 1 + dp[i-1][j-1];   
                }
                else{
                    //nOT match 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string reversedString = s;
        reverse(reversedString.begin(),reversedString.end());

        return lcs(s,reversedString)  ;

    }
};