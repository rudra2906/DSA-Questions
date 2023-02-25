class Solution {
    
private:
    int maxi(int arr[] , int size)
    {
        int maxi = INT_MIN;
        for( int i = 0 ; i<size ;i++)
        {
            if(maxi<arr[i]){
                maxi = arr[i];
            }
        }
        return maxi;
    } 

public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        // NSR
        
        stack<pair<int ,int>> rs;
        vector<int> r;
        
        for( int i = n-1 ; i>=0 ; i-- )
        {
            //
            while(!rs.empty() && heights[i] <= rs.top().first)
            {
                rs.pop();
            }
            
            // jab empty ho jayga
            if( rs.empty() )
            {
                r.push_back(n);
            }
            
            // array se chota element aagar stackme hai to uska index push kar do
            else if( !rs.empty() && heights[i] > rs.top().first)
            {
                r.push_back(rs.top().second);
            }
            
            rs.push({heights[i],i});
            
        }
        
        reverse(r.begin(),r.end());
        
         // NSL
        
        stack<pair<int ,int>> ls;
        vector<int> l ;
        
        for( int i = 0 ; i<n ; i++ )
        {
            //
            while(!ls.empty() && heights[i] <= ls.top().first)
            {
                ls.pop();
            }
            
            // jab empty ho jayga
            if( ls.empty() )
            {
                l.push_back(-1);
            }
            
            // array se chota element aagar stackme hai to uska index push kar do
            else if( !ls.empty() && heights[i] > ls.top().first)
            {
                l.push_back(ls.top().second);
            }
            
            ls.push({heights[i],i});
            
        }
        
        // width
        int width[n] ;
        for(int i=0 ;i<n ; i++ )
        {
            width[i]= ((r[i]-l[i])-1)*heights[i];
        }

        // maximum
        int  maxx = maxi(width,n);
        return maxx;

        

    }
};