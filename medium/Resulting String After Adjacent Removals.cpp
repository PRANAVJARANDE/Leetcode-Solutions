class Solution {
public:

    bool check(int cr,int c2)
    {
        int pv=(cr-1+26)%26;
        int nx=(cr+1)%26;
        if(c2==pv || c2==nx)return 1;
        return 0;
    }

    string resultingString(string s) 
    {
        stack<char>s1;
        for(auto x:s)
        {
            if(s1.empty())s1.push(x);
            else
            {
                char pv=s1.top();
                if(check(pv-'a',x-'a'))s1.pop();
                else s1.push(x);
            }
        }
        int sz=s1.size();
        string ans(sz,'0');
        int in=sz-1;
        while(!s1.empty())
        {
            ans[in]=s1.top();
            in--;
            s1.pop();
        }
        return ans;
    }
};
