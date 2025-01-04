class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        map<char,int> l,r;
        for(int i=0;i<n;i++)
        {
            if(l.find(s[i])==l.end())l[s[i]]=i;
            r[s[i]]=max(r[s[i]],i);
        }


        int ans=0;
        for(char c='a';c<='z';c++)
        {
            if(l.find(c)!=l.end())
            {
                map<char,int>m;
                for(int i=l[c]+1;i<=r[c]-1;i++)
                {
                    m[s[i]]++;
                }
                ans+=m.size();
            }
        }
        return ans;

    }
};
