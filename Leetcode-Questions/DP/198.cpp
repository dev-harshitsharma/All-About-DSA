class Solution {

public:
    int solution(int index, vector<int> &nums, vector<int>& dp){
        if( index == 0) return nums[0];
        if(index < 1) return 0;

        if( dp[index] != -1) return dp[index];

        int pick = nums[index] + solution(index-2,nums,dp);
        int notPick = 0 + solution(index-1,nums,dp);

        return dp[index] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solution(n-1,nums,dp);
    }

    /* 
        Solution with space optimization 
            // int n = nums.size();
        // int prev = nums[0];
        // int prev2  = 0;

        // for(int i =0; i< n ;i ++ ){
            
        //     int take = nums[i];
        //     if(i>1) {
        //         take += prev2;
        //     }
        //     int notTake = prev;
        //     int current = max(take, notTake);
        //     prev2 = prev;
        //     prev= current;
        // }

        // return prev;
    
    
    */ 
};