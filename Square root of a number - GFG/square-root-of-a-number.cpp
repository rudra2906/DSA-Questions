//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long square_root = 1;
        long long low = 1;
        long long high = x;
        long long mid =( low + high )/2;
        
        while(low<=high)
        { 
            mid =( low + high )/2;
            if(mid*mid <= x)
            {
                square_root = mid;
                low = mid +1;
            }
            else
            {
                high = mid-1;
            }
        }
        return square_root;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends