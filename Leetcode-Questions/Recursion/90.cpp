class Solution {
public:
    void findSubsets(int index,vector<int> &arr , vector<int> &ds, vector<vector<int>> &ans ){
        ans.push_back(ds); //intitalizing the array where we want to store 
        for( int i =index ; i < arr.size();i ++){
            if( i != index && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubsets(i+1,arr,ds,ans);
            ds.pop_back();
        }       
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }
};