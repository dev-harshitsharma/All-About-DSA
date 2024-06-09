class Solution {
public:
    //Memoization on the recursive function 
    int solution(int i , int j , vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
         //base case 
        if(i == n-1) return triangle[n-1][j];

        //down and diagonal are the only options
        if( dp[i][j] != -1) return dp[i][j];
        int firstMove = triangle[i][j] + solution(i+1,j,triangle,n,dp);
        int secondMove = triangle[i][j] + solution(i+1,j+1,triangle,n,dp);
        
        return dp[i][j] = min(firstMove,secondMove);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solution(0,0,triangle,n,dp);

        //Tabluation 
        //Base Case 
        // for( int k =0 ;k<n;k++){
        //     dp[n-1][k] = triangle[n-1][k];
        // }

        // for( int i = n-2;i>=0;i--){
        //     for( int j = i;j>=0;j--){
        //         int choiceOne = triangle[i][j] + dp[i+1][j];
        //         int choiceTwo = triangle[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(choiceOne,choiceTwo);
        //     }
        // }
        
        // return dp[0][0];

        //SPACE OPTIMIZATION
        vector<int> front(n,0);
        vector<int> current(n,0);
        for( int k =0 ;k<n;k++){
            front[k] = triangle[n-1][k];
        }

        for( int i = n-2;i>=0;i--){
          
            for( int j = i;j>=0;j--){
                int choiceOne = triangle[i][j] + front[j];
                int choiceTwo = triangle[i][j] + front[j+1];
                current[j] = min(choiceOne,choiceTwo);
            }
            front = current;
        }
        
        return front[0];

    }

    

    
};