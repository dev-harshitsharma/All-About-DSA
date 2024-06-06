class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index =-1;
        int n = nums.size();

        //agar breakpoint dhundna h to second last element se hi milega
        for(int i =n-2 ; i>= 0;i--){
            if(nums[i] < nums[i+1]){
                index =i;
                break;
            }
        }

        //if breakpoint is not there 
        if(index ==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        //if index is found and we have to do the next permutation 
        for(int i = n-1;i>=0;i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());

    }
};


/*
    First Observation : We need to find oput the breakpoint a point whweere 
    element at this index will be samllere than the next index 

    nums[i]--< nums[i+1];

    Second Observation : We will take the greater nunmber than 1 but smallest among the greatest 

    Third obeservation : If we get a smallest greateerr then after that we  will go by t-- sorted order because it will be slightly greater than the numsay 

    Step 1 -- Find out the dipped pouint in the numsay 

    if(no dip) -> reverse the aaray 

    step 2-> Find next greater and swap 

   if(nums[-- > nums[index]) swap the element 

   step-3 make as small as possibl--
    Reverse ther numsay and we have the necxt permutation 
