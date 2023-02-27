class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        
        // for maximum left side
        int maxLeft[size] ;
        maxLeft[0] = height[0];
        
        for(int i=1 ; i<size ; i++)
        {
            maxLeft[i] = max( height[i] , maxLeft[i-1] );
        }
        
        // for maximum right side
        int maxRight[size];
        maxRight[size-1] = height[size-1];
        
        for( int i=(size-1)-1 ; i>=0 ; i--)
        {
            maxRight[i] = max( maxRight[i+1] , height[i] );
        }
        
        // (min(maxLeft, maxRight) )-arr[i]
        int water[size];
        for(int i=0 ; i<size ; i++ )
        {
            water[i] = min(maxLeft[i] , maxRight[i]) - height[i];
        }
        
        // total sum of water
        int sum = 0 ;
        for(int i=0 ; i<size ; i++)
        {
            sum =sum + water[i];
        }
        return sum;
    }
};