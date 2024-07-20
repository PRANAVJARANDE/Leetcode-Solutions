class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n=r.size();
        int m=c.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(r[i]>c[j])
                {
                    ans[i][j]=c[j];
                    r[i]-=c[j];
                    c[j]=0;
                }
                else
                {
                    ans[i][j]=r[i];
                    c[j]-=r[i];
                    r[i]=0;
                }
            }
        }
        return ans;
    }
};
