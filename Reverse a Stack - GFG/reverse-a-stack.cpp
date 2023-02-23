//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    void insertAtBottom(stack<int> &s, int temp )
    {
        // base case
        while(s.empty())
        {
            s.push(temp);
            return;
        }
        
        // recursive relation
        
        int t = s.top();
        s.pop();
        
        insertAtBottom(s,temp);
        
        s.push(t);
        
    }

//apprach 1 - new stack create kr lenge or usmen daalte jaynge 
//  approach 2 - isme extra space nahi lagega recursion se karenge ek case khud se karenge baki recursion sabal lega
// fir bottom me insert kr lenge
public:
    void Reverse(stack<int> &St){
        
        // base case
        while(St.empty()){
            return ;
        }
        
        // recursive relation
        int temp = St.top();
        St.pop();
        
        Reverse( St );
        
        insertAtBottom( St, temp );
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends