class Solution {
public:
    int maxDepth(string s) 
    {
        stack<char> s1;
        int ans=0;
        for(char x: s)
        {
            if(x=='(')s1.push(x);
            else if(x==')')s1.pop();
            ans=max(ans,(int)s1.size());
        }
        return ans;
    }
};
