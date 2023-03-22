class Solution {
private:
    bool subsetSum(vector<int>& arr, int n , int sum )
    {
        int p[n+1][sum+1];
        for(int i=0;i<n+1 ;i++)
        {
            for(int j=0 ; j<sum+1 ; j++ )
            {
                if(i==0)
                    p[i][j]=false;
                else if(j==0)
                    p[i][j]=true;
            }
        }
        for(int i=1 ; i<n+1 ; i++)
        {
            for( int j=1; j<sum+1 ; j++ )
            {
                if(arr[i-1]<=j)
                {
                    p[i][j] = (p[i-1][ j - arr[i-1]] || p[i-1][j]);
                }
                else
                {
                    p[i][j] = p[i-1][j];
                }
            }
        }
        return p[n][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size(); 
        
        int sum = 0;
        for( int i=0; i<size ; i++){
            sum = sum+nums[i];
        }
        if(sum%2 != 0 )//odd hai to
            return false;
        else
        {
            return subsetSum(nums,size,sum/2);
        }
    }
};