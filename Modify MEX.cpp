class Solution {
  public:
    int modifyMEX(int n, vector<int> &a) {
        int mex=0;
        vector<int> m(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(a[i]<=n)m[a[i]]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            if(m[i]==0)
            {
                if(ans==INT_MAX)return -1;
                return ans;
            }
            ans=min(ans,m[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
