class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(subsetSum + 1, 0));

        dp[0][0] = 1;

        if (nums[0] <= subsetSum) {
            dp[0][nums[0]] += 1;
        }

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= subsetSum; sum++) {
                int notTake = dp[i-1][sum];
                int take = 0;
                if (nums[i] <= sum) {
                    take = dp[i-1][sum - nums[i]];
                }
                dp[i][sum] = take + notTake;
            }
        }

        return dp[n-1][subsetSum];
    }
};