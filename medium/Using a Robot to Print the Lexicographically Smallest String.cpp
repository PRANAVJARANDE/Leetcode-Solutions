class Solution {
public:
    string robotWithString(string s) 
    {
        int n=s.size();
        map<char,int>m;
        for(int i=0;i<n;i++)m[s[i]]=i;

        int in=0;
        string ans(n,'0');
        stack<char>s1;

        int j1=0;
        for(int ch='a';ch<='z';ch++)
        {
            while(!s1.empty() && s1.top()<=ch)
            {
                ans[in++]=s1.top();
                s1.pop();
            }
            if(m.find(ch)==m.end())continue;
            while(j1<n && j1<=m[ch])
            {
                if(s[j1]==ch)ans[in++]=ch;
                else s1.push(s[j1]);
                j1++;
            }
        }
        while(!s1.empty())
        {
            ans[in++]=s1.top();
            s1.pop();
        }
        return ans; 
    }
};
