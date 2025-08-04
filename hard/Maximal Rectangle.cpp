class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')a[i][j]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j]+=a[i][j-1];
            }
        }

        int ans=0;
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {
                int height=0;
                int cnt=0;
                int sz=r-l+1;
                for(int i=0;i<n;i++)
                {
                    int cs=a[i][r];
                    if(l-1>=0)cs-=a[i][l-1];
                    if(cs==sz)cnt++;
                    else cnt=0;
                    height=max(height,cnt);
                }
                ans=max(ans,sz*height);
            }
        }    
        return ans;
    }
};
