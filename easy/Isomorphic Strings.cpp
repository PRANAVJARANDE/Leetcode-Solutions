class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char,char> m,n;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end())
            {
                if(m[s[i]]!=t[i])
                {
                    return 0;
                }
            }
            else
            {
                m[s[i]]=t[i];
            }

            if(n.find(t[i])!=n.end())
            {
                if(n[t[i]]!=s[i])
                {
                    return 0;
                }
            }
            else
            {
                n[t[i]]=s[i];
            }

        }
        return 1;
    }
};
