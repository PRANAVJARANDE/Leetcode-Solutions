class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<int> s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                s1.push(i);
            }
            else if(s[i]==')')
            {
                int k=s1.top();
                s1.pop();
                reverse(s.begin()+k+1,s.begin()+i);
                s.erase(i,1);
                s.erase(k,1);
                i=i-2;
            }
        }
        return s;
    }
};
