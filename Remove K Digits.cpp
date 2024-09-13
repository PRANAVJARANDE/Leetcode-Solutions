class Solution {
public:
    string removeKdigits(string s, int k) 
    {
        stack<char> s1;
        for(char d: s)
        {
            while(!s1.empty() && k>0 && s1.top()>d)
            {
                s1.pop();
                k--;
            }
            s1.push(d);
        }
        while(!s1.empty() && k>0)
        {
            s1.pop();
            k--;
        }
        int n=s1.size();
        string ans(n,'0');
        int in=n-1;
        while(!s1.empty())
        {
            ans[in]=s1.top();
            in--;
            s1.pop();
        }

        in=0;
        while(in<ans.size() && ans[in]=='0')
        {
            in++;
        }
        if(in==ans.size())return "0";
        ans=ans.substr(in);
        return ans;
    }
};
