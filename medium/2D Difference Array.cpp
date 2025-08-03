class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& a,vector<vector<int>>& opr) 
    {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>ps(n+1,vector<int>(m+1,0));
        for(auto x:opr)
        {
            int v=x[0];
            int tx=x[1],ty=x[2];
            int bx=x[3]+1,by=x[4]+1;
            ps[tx][ty]+=v;
            ps[bx][by]+=v;
            ps[bx][ty]-=v;
            ps[tx][by]-=v;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0)ps[i][j]+=ps[i-1][j];
                if(j-1>=0)ps[i][j]+=ps[i][j-1];
                if(i-1>=0 && j-1>=0)ps[i][j]-=ps[i-1][j-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]+=ps[i][j];
            }
        }
        return a;
    }
};
