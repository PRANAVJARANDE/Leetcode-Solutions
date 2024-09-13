class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int n=s.size();
        vector<int> vis(26,0);
        vector<int>li(26,0);
        for(int i=0;i<n;i++)
        {
            li[s[i]-'a']=i;
        }

        stack<char> s1;
        for(int i=0;i<n;i++)
        {
            if(vis[s[i]-'a']==1)continue;
            vis[s[i]-'a']=1;

            while(!s1.empty() && s1.top()>s[i] && i<li[s1.top()-'a'])
            {
                vis[s1.top()-'a']=0;
                s1.pop();
            }
            s1.push(s[i]);
        }
        int sz=s1.size();
        string ans(sz,'0');
        int in=s1.size()-1;
        while(in>=0)
        {
            ans[in]=s1.top();
            s1.pop();
            in--;
        }
        return ans;
    }
};
