class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    int oc=0,zc=0;
                    for(int z=0;z<m;z++)
                    {
                        bool td=0;
                        if(a[i][z]==0)
                        {
                            td=!td;
                        }
                        if(a[j][z]==td)zc++;
                        else oc++;
                    }
                    if(zc==0 || oc==0)cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
