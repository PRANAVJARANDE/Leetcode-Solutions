class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n=s.size();
        unordered_map<char,int> m;
        int ans=0,ts=0;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
            while(m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                ans+=n-i;
                m[s[ts]]--;
                ts++;
            }
        }
        return ans;
    }
};
