//COLUMNS TECHNIQUE
class Solution {
public:
    int countSquares(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                a[i][j]+=a[i][j-1];

        int ans=0;
        for(int l=0;l<m;l++)
        {
            for(int r=l;r<m;r++)
            {
                int cnt=0;
                int s=r-l+1;
                for(int i=0;i<n;i++)
                {
                    int cs=a[i][r];
                    if(l-1>=0)cs-=a[i][l-1];
                    if(cs==s)cnt++;
                    else cnt=0;
                    if(cnt>=s)ans++;
                }
            }
        }
        return ans;
    }
};




//PSUM
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
