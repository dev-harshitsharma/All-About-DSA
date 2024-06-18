class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //Declaration of the dp array 
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        //base case 
        cout<<"flow"<<endl;
        for(int t=0;t<= amount;t++){
            if( t % coins[0] == 0){
                prev[t]=1;
            }else{
                prev[t]=0;
            }
        }
        for( int index =1;index<n;index++ ){
            for(int target =0;target<=amount;target++){
                int notTake = prev[target];
                int take =0;
                if(coins[index] <= target){
                    take = curr[target-coins[index]];
                }
                curr[target] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};