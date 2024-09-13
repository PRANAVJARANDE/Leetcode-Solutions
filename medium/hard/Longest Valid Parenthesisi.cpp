class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> s1;
        s1.push(-1);
        int maxL=0;

        for(int i=0;i<s.size();i++)
        {
            if(s1.top()!=-1 && s[i]==')' && s[s1.top()]=='(')
            {
                s1.pop();
                maxL=max(maxL,i-s1.top());
            }
            else
            {
                s1.push(i);
            }
        }
        
        return maxL;
    }
};
