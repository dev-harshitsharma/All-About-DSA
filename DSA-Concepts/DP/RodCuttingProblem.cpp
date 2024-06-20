int solve(int index,int N,vector<int> &arr,vector<vector<int>> &dp){
	//Base case
	if(index == 0){
		return N*arr[0];
	}
	if(dp[index][N] != -1) return dp[index][N];
	int notTake = 0+ solve(index-1,N,arr,dp);
	int take = INT_MIN;
	int rodLength = index+1;
	if(rodLength <= N){
		take = arr[index] + solve(index,N-rodLength,arr,dp);
	}

	return dp[index][N] = max(take,notTake);
}

int cutRod(vector<int> &price, int n)
{
    // Initialize dp array with 0s
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base case 
    for (int N = 0; N <= n; N++) {
        dp[0][N] = N * price[0];
    }

    for (int index = 1; index < n; index++) {
        for (int N = 0; N <= n; N++) {
            int notTake = dp[index - 1][N];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= N) {
                take = price[index] + dp[index][N - rodLength];
            }
            dp[index][N] = max(take, notTake);
        }
    }

    // Return the maximum profit
    return dp[n - 1][n];
}
    