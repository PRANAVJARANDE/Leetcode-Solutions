class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) 
    {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)a[i][j]+=a[i-1][j];
                if(j-1>=0)a[i][j]+=a[i][j-1];
                if(i-1>=0 && j-1>=0)a[i][j]-=a[i-1][j-1];
            }
        }
        int ans=0;
        for(int x1=0;x1<n;x1++)
        {
            for(int x2=x1;x2<n;x2++)
            {
                for(int y1=0;y1<m;y1++)
                {
                    for(int y2=y1;y2<m;y2++)
                    {
                        int cs=a[x2][y2];
                        if(x1-1>=0)cs-=a[x1-1][y2];
                        if(y1-1>=0)cs-=a[x2][y1-1];
                        if(x1-1>=0 && y1-1>=0)cs+=a[x1-1][y1-1];
                        if(cs==t)ans++;
                    }
                }
            }
        }
        return ans;
    }
};
