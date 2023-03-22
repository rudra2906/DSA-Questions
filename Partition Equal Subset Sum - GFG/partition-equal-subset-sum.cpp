//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int subsetSum(int n , int arr[] , int sum)
    {
        // initilization
        int p[n+1][sum+1];
        for(int i=0 ; i<n+1 ; i++)
        {
            for(int j=0 ; j<sum+1 ; j++)
            {
                if(i==0)
                    p[i][j]=0;
                else if(j==0)
                    p[i][j] = 1;
            }
        }
        
        for(int i=1 ; i<n+1 ; i++)
        {
            for(int j=1 ; j<sum+1 ; j++)
            {
                if(arr[i-1]<=j)
                {
                    p[i][j]=p[i-1][j-arr[i-1]]||p[i-1][j];
                }
                else//exclude
                    p[i][j]=p[i-1][j];
            }
        }
        return p[n][sum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N ; i++)
        {
            sum = sum + arr[i];
        }
        if( sum%2 != 0 )//odd
            return 0;
        else
            return subsetSum(N,arr,sum/2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends