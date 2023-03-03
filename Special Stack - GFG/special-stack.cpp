//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

stack<int>ss;
void push(stack<int>& s, int a){
	s.push(a);
	if( ss.empty() || a <= ss.top() )
	{
	    ss.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n){
	    return true;
	}
	else
	{
	    false;
	}
}

bool isEmpty(stack<int>& s){
    
	if(s.empty())
	{
	    return true;
	}
	else
	{
	    return false;
	}
}

int pop(stack<int>& s){
    
    if(s.empty())
    {
        return-1;
    }
    
	int temp = s.top();
	s.pop();
	
	if(temp == ss.top())
	{
	    ss.pop();
	}
	return temp;
}

int getMin(stack<int>& s){
    
	if(ss.size()==0)
	{
	    return -1;
	}
	else
	{
	    return ss.top();
	}
}