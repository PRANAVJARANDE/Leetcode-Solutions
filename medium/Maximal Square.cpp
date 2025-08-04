class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')a[i][j]=1;
                if(j-1>=0)a[i][j]+=a[i][j-1];
            }
        }
        int ans=0;
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {
                int cnt=0;
                int width=r-l+1;
                for(int i=0;i<n;i++)
                {
                    int ones=a[i][r];
                    if(l-1>=0)ones-=a[i][l-1];
                    if(ones==width)cnt++;
                    else cnt=0;
                    if(cnt==width)ans=max(ans,width*width);
                }
            }
        }
        return ans;
    }
};
