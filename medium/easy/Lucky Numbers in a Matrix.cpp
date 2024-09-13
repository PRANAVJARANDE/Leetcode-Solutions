class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int> r(n,INT_MAX);
        vector<int> c(m,INT_MIN);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                r[i]=min(r[i],a[i][j]);
                c[j]=max(c[j],a[i][j]);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==c[j] && c[j]==r[i])
                {
                    ans.push_back(a[i][j]);
                }
            }
        }
        return ans;
    }
};
