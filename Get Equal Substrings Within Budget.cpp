class Solution {
public:
    int equalSubstring(string s, string t, int mx) 
    {
        int ans=0,curr=0,n=s.size();
        int l=0;
        for(int i=0;i<n;i++)
        {
            curr+=abs(s[i]-t[i]);
            while(curr>mx)
            {
                curr-=abs(s[l]-t[l]);;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
        
    }
};
