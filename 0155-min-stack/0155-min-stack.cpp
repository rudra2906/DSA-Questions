class MinStack {
public:
    
    stack<int>ss;
    stack<int>s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        s.push(val);
        if( ss.empty() || val<=ss.top())
        {
            ss.push(val);
        }
        
    }
    
    void pop() {

        int temp = s.top();
        s.pop();
        if(temp == ss.top())
        {
            ss.pop();
        }
    }
    
    int top() {
        
        if(s.empty())
        {
            return -1;
        }
        else
        {
            return s.top();
        }
        
    }
    
    int getMin() {
        
        if(ss.empty())
        {
            return -1;
        }
        else
        {
            return ss.top();
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */