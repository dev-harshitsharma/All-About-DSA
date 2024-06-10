class Solution {
public:
    bool solve( int index, int target, vector<int> &nums,vector<vector<int>> &dp) {
        if( target == 0) return true;
        if( index == 0) return (nums[0] == target); 

        if(dp[index][target] != -1) return dp[index][target];
        bool notTake = solve(index-1,target,nums,dp);
        bool take = false;
        if(target >= nums[index])
            take = solve(index-1,target-nums[index],nums,dp);
        
        return dp[index][target] = take | notTake;
        
    }
    bool canPartition(vector<int>& nums) {

        int totalSum =0;
        for( int i =0;i<nums.size();i++) {
            totalSum += nums[i];
        }
        int target = totalSum/2;
        if(totalSum %2 ) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums.size()-1, target,nums,dp);
    }
};