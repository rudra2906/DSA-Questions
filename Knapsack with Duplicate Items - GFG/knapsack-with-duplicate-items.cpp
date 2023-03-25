//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// using recursion
class Solution{
public:
    int t[1001][1001];
    Solution(){
      memset(t,-1,sizeof(t));
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        //memset(t, -1, sizeof(t));
        // base case
        if( N==0 || W==0 )
        {
            return 0;
        }
        
        if( t[N][W] != -1 )
        {
            return t[N][W];
        }
        
        // recursive relation
        if(wt[N-1]<=W)
        {
            return t[N][W]=max( (val[N-1] + knapSack(N,W-wt[N-1], val, wt) ), (knapSack(N-1 , W ,val,wt) ));
        }
        else
        {
            return t[N][W] = knapSack( N-1,W,val,wt);
        }
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