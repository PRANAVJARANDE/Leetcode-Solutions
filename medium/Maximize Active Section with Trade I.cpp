class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) 
    {
        int n=s.size();
        int ans=0;
        for(auto x:s)if(x=='1')ans++;
        vector<int>v1;
        for(int i=0;i<n;)
        {
            if(s[i]=='0')
            {
                int cnt=0;
                while(i<n && s[i]=='0')
                {
                    i++;
                    cnt++;
                }
                v1.push_back(cnt);
            }
            else
            {
                i++;
            }
        }
        int ta=0;
        for(int i=1;i<v1.size();i++)
        {
            int res=v1[i]+v1[i-1];
            ta=max(ta,res);
        }
        ans+=ta;
        return ans;
    }
};
