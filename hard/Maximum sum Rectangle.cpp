class Solution {
  public:
    int maxRectSum(vector<vector<int>> &a) 
    {
        int n=a.size();
        int m=a[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,a[i][j]);
                if(j-1>=0)a[i][j]+=a[i][j-1];
            }
        }
        if(ans<=0)return ans;
        
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {   
                int cs=0;
                for(int i=0;i<n;i++)
                {
                    int rs=a[i][r];
                    if(l-1>=0)rs-=a[i][l-1];
                    cs+=rs;
                    if(cs<=0)cs=0;
                    ans=max(ans,cs);
                }
            }
        }
        return ans;
    }
};
