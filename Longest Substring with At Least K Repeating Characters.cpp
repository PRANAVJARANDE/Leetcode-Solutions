class Solution {
public:

    bool check(unordered_map<char,int>&m,int k)
    {
        for(auto x: m)
        {
            if(x.second<k)
            {
                return 0;
            }
        }
        return 1;
    }

    int longestSubstring(string s, int k) 
    {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                if(check(m,k))
                {
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
