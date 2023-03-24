//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	
	    int range=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        range = range + arr[i];
	    }
	    
	    //int sum = range/2;
	   // subset sum problem
	   
	   bool dp[n+1][range+1];
	   
	   // Initilization
	   for(int i =0; i<n+1 ; i++)
	   {
	       for(int j=0 ; j<range+1 ; j++ )
	       {
	           if(i==0)
	           {
	               dp[i][j]=false;
	           }
	           if(j==0)
	           {
	               dp[i][j]=true;
	           }
	       }
	   }
	   
	   // top down
	   for( int i=1 ; i<n+1 ; i++ )
	   {
	       for( int j=1; j<range+1 ; j++ )
	       {
	           if(arr[i-1]<=j)
	           {
	               //include or exclude
	               dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	           }
	           else
	           {
	               dp[i][j]=dp[i-1][j];
	           }
	       }
	   }
	   
	   // creating vector for true value
	   vector<int>vec;
	   for(int i=0 ;i<=range/2 ;i++ )
	   {
	       if(dp[n][i]==true)
	       {
	           vec.push_back(i);
	       }
	   }
	   
	   // creating variable for minimum value
	   int MN= INT_MAX;
	   
	   for(int i=0; i<vec.size() ; i++ )
	   {
	       MN = min(MN,range-(2*(vec[i])));
	   }
	   
	   return MN;
	}
	
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends