//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        int size = n;
        
        // for maximum left side
        int maxLeft[size] ;
        maxLeft[0] = arr[0];
        
        for(int i=1 ; i<size ; i++)
        {
            maxLeft[i] = max( arr[i] , maxLeft[i-1] );
        }
        
        // for maximum right side
        int maxRight[size];
        maxRight[size-1] = arr[size-1];
        
        for( int i=(size-1)-1 ; i>=0 ; i--)
        {
            maxRight[i] = max( maxRight[i+1] , arr[i] );
        }
        
        // (min(maxLeft, maxRight) )-arr[i]
        int water[size];
        for(int i=0 ; i<size ; i++ )
        {
            water[i] = min(maxLeft[i] , maxRight[i]) - arr[i];
        }
        
        // total sum of water
        long long sum = 0 ;
        for(int i=0 ; i<size ; i++)
        {
            sum =sum + water[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends