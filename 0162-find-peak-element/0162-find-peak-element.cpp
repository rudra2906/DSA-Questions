class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //with 0(n) time complexity 
        //bruteforce approach
        if(nums.size() == 0)
            return 0;
        
        int ans;
        for(int i=0; i<nums.size() ; i++)
        {
            if(((i==0) || (nums[i-1]<nums[i])) && ( (i==nums.size()-1) || (nums[i]>nums[i+1]) ))
                ans = i ;
        }
        return ans;
        
    }
};