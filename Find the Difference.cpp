class Solution {
public:
    char findTheDifference(string s, string g) 
    {
        int a=0;
        for(int i=0;i<s.size();i++)
        {
            a-=s[i];
            a+=g[i];
        }
        return a+g[g.size()-1];
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
            {
                return t[i];
            }
        }
        return t[t.size()-1];
    }
};
