class Solution {
public:
    string makeGood(string s) 
    {
        int d='a'-'A';
        stack<char> s1;
        for(char x: s)
        {
            if(!s1.empty())
            {
                int g=abs(s1.top()-x);
                if(g==d)
                {
                    s1.pop();
                    continue;
                }
            }
            s1.push(x);
        }

        int sz=s1.size();
        string ans(sz,'0');
        int in=sz-1;
        while(!s1.empty())
        {
            ans[in]=s1.top();
            s1.pop();
            in--;
        }
        return ans;
        
    }
};
