class Solution {
public:
    bool buddyStrings(string s, string g) 
    {
        if(s.size()!=g.size())
        {
            return 0;
        }
        int n=s.size();
        //check duplicates
        if(s==g)
        {
            string a=s;
            sort(a.begin(),a.end());
            for(int i=0;i<n-1;i++)
            {
                if(a[i]==a[i+1])
                {
                    return 1;
                }
            }
        }

        int fi=-1,si=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=g[i])
            {
                if(fi==-1)
                {
                    fi=i;
                }
                else if(si==-1)
                {
                    si=i;
                }
                else
                {
                    return 0;
                }
            }
        }
        if(si==-1)
        {
            return 0;
        }

        if(s[fi]==g[si] && s[si]==g[fi])
        {
            return 1;
        }
        return 0;
    }
};
