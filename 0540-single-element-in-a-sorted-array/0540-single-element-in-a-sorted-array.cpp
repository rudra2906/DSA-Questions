class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()-1==0)
        {
            return nums[0];
        }
        int ans;
        for(int i = 0; i<=nums.size()-1 ; i++)
        {
            if(i==0)
            {
                if(nums[i]!=nums[i+1])
                    ans = nums[i];
                continue;
            }
            else if(i == (nums.size()-1) )
            {
                if(nums[i]!=nums[i-1])
                    ans = nums[i];
            }
            else
            {
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])
                    ans= nums[i];
            }
        }
        return ans;
    }
};