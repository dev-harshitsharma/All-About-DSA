class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n  = intervals.size();
        sort(intervals.begin(),intervals.end());

        for( int i = 0; i< n ; i++) {
            int startingValue = intervals[i][0];
            int endingValue = intervals[i][1];

            if(!ans.empty() && endingValue <= ans.back()[1]){
                continue;
            }
            for( int j =i+1; j< n ;j++){
                if(intervals[j][0] <= endingValue ){
                    endingValue = max(endingValue,intervals[j][1]);
                }
                else{
                    break;
                }
            }
             ans.push_back({startingValue,endingValue});
        }
        return ans;
    }
};

/*
    1. Brute Force 
        ->Bring all the intervals closer so we easily get the idea of the intervals - Sort them 
        ->Hypothetically say the first one is the overlapping interval
            . If the first element is below the last element then yes they are a interval for sure 
        -> Repeat the process for every index which is not in the interval


*/