class Solution {
public:
    bool isValid(string s) {
        
        stack<char> tak;
        
        for(int i=0 ; i<s.length() ;i++)
        {
            char ch = s[i];
            
            //for opening barckets             
            if( ch=='(' || ch == '{' || ch == '[')
            {
                tak.push(ch);
            }
            
            // for closing brackets
            else
            {
                
                if(!tak.empty())
                {
                    char temp = tak.top();
                    
                    if(( ch==')' && temp =='(') || ( ch=='}' && temp =='{') || ( ch==']' && temp =='['))
                    {
                        tak.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
             
        }
        
        if(tak.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};