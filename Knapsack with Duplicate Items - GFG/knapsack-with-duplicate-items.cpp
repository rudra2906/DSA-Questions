//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// using recursion + memoziation
// class Solution{
// public:
//     int t[1001][1001];
//     Solution(){
//       memset(t,-1,sizeof(t));
//     }
    
//     int knapSack(int N, int W, int val[], int wt[])
//     {
//         //memset(t, -1, sizeof(t));
//         // base case
//         if( N==0 || W==0 )
//         {
//             return 0;
//         }
        
//         if( t[N][W] != -1 )
//         {
//             return t[N][W];
//         }
        
//         // recursive relation
//         if(wt[N-1]<=W)
//         {
//             return t[N][W]=max( (val[N-1] + knapSack(N,W-wt[N-1], val, wt) ), (knapSack(N-1 , W ,val,wt) ));
//         }
//         else
//         {
//             return t[N][W] = knapSack( N-1,W,val,wt);
//         }
//     }

// };

// using top down approach
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        // initilization
        for(int i=0; i<N+1 ;i++)
        {
            for(int j=0 ; j<W+1 ; j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=0;
            }
            
        }
        for(int i=1; i<N+1 ; i++ )
        {
            for(int j=1 ;j<W+1;j++)
            {
                if( wt[i-1] <= j )
                {
                    dp[i][j] = max( val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }

};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends