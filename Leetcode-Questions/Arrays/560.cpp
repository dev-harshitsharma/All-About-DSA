class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> myMap;
        myMap[0] = 1; //initializing the map with a key of 1 and a value of 1 
        int preSum = 0;
        int count = 0;
        for (int i = 0; i < size; i++) {
            preSum = preSum + nums[i];
            int removedPart = preSum - k;
            count += myMap[removedPart];
            myMap[preSum] += 1;
        }
        return count;
    }
};