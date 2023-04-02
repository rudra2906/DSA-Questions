//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        long long int size = N;
        long long int dp[size+1][sum+1];
        for(int i=0; i<size+1 ;i++)
        {
            for(int j=0; j<sum+1 ; j++)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1; i<size+1 ; i++)
        {
            for(int j=1; j<sum+1 ; j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]= dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[size][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends