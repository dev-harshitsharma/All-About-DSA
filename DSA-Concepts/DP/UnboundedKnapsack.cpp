int solve(int index , int w , vector<int> &profit,vector<int> &weight){
    if (index == 0) {
        return (w / weight[0]) * profit[0];
    }

    int notTake = solve(index - 1, w, profit, weight);
    int take = -1e9;
    if (w >= weight[index]) {
        take = profit[index] + solve(index, w - weight[index], profit, weight);
    }

    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // return solve(n-1,w,profit,weight);(w / weight[0]) * profit[0]

    //Lets Apply tabulation directly 
    //states are weight and index 
    //weight - 0 -> maxweight , index 0 to n-1

    //Base casen , dependent on only index 

    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

   for (int wt = 0; wt <= w; wt++) {
        if (wt >= weight[0])
            dp[0][wt] = (wt / weight[0]) * profit[0];
        else 
            dp[0][wt] = -1e9;
    }

    // Fill the dp array for the rest of the cases
    for (int index = 1; index < n; index++) {
        for (int wt = 0; wt <= w; wt++) {
            int notTake = dp[index - 1][wt];
            int take = 0;
            if (wt >= weight[index])
                take = profit[index] + dp[index][wt - weight[index]];
            dp[index][wt] = max(take, notTake);
        }
    }

    return dp[n-1][w]; 

}