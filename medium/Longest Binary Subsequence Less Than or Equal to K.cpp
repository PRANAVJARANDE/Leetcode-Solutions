#define ll long long
class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int ans=0;
        reverse(s.begin(),s.end());
        int n=s.size();
        ll cs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')ans++;
            else if(i<=32)
            {
                ll r=(1ll<<i);
                if(cs+r<=k)
                {
                    cs+=r;
                    ans++;
                }
            }
        }
        return ans;
    }
};
