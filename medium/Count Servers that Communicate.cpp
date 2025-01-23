class Solution {
public:
    int countServers(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int>r(n,0),c(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1 && (r[i]>1 || c[j]>1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
