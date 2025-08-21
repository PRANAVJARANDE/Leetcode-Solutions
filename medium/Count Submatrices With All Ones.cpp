class Solution {
public:
    int numSubmat(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j]+=a[i][j-1];
            
        int ans=0;
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {
                int sz=r-l+1;
                int cnt=0;
                for(int j=0;j<n;j++)
                {
                    int res=a[j][r];
                    if(l-1>=0)res-=a[j][l-1];
                    if(res==sz)cnt++;
                    else cnt=0;
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};
