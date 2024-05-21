class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        int duplicate;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>1){
                duplicate=it.first;
                break;
            }
        }
        return duplicate;
    }
};