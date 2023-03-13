//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
int r[101][100001];
class Solution{   
public:
    
    bool solve( vector<int>&arr , int sum , int size )
    {
        if( sum == 0 )
        {
            return true;
        }
        if( size == 0 )
        {
            return false;
        }

        if(r[size][sum] != -1)
        {
            return r[size][sum];
        }
        if( arr[size-1] <= sum )
        {
            // include
            return r[size][sum] = solve( arr , sum-arr[size-1] , size-1)||solve(arr,sum,size-1);
        }
        else
        {
            return r[size][sum] = solve(arr,sum,size-1);
        }
        
        return r[size][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int size = arr.size();
        memset(r,-1,sizeof(r));
        return solve( arr , sum , size );
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends