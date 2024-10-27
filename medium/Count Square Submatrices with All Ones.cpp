class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int ans=0;
        int n=a.size(),m=a[0].size();
        vector<vector<int>> psum(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                psum[i][j]=a[i][j];
                if(i-1>=0)psum[i][j]+=psum[i-1][j];
                if(j-1>=0)psum[i][j]+=psum[i][j-1];
                if(i-1>=0 && j-1>=0)psum[i][j]-=psum[i-1][j-1];
            }
        }
        for(int s=1;s<=min(n,m);s++)
        {
            for(int i=s-1;i<n;i++)
            {
                for(int j=s-1;j<m;j++)
                {
                    int res=psum[i][j];
                    if(i-s>=0)res-=psum[i-s][j];
                    if(j-s>=0)res-=psum[i][j-s];
                    if(i-s>=0 && j-s>=0)res+=psum[i-s][j-s];
                    if(res==s*s)ans++;
                }
            }
        }
        return ans;
    }
};
