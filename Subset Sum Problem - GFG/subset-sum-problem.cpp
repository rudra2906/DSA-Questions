//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    
    bool solve(int size, vector<int>arr , int sum)
    {
        bool dp[size+1][sum+1];
        for(int i =0 ; i<size+1 ;i++ )
        {
            for(int j= 0; j<sum+1 ; j++ )
            {
                if(i==0 )
                    dp[i][j] = false;
                    
                if(j==0)
                    dp[i][j] = true;
                    
                else
                    dp[i][j] = false; // handle the missing base case
            }
            
        }
        for(int i = 1; i<size+1 ; i++ )
        {
            for(int j= 1 ; j<sum+1 ; j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j]=dp[i-1][j];
                    
                }
            }
        }
        
        return dp[size][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int size = arr.size();
        return solve(size,arr,sum);
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