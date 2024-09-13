class Solution {
public:
    int minimumArea(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }   
            }
        }
        int l=0,r=n-1;
        while(l<n && row[l]==0)
        {
            l++;
        }
        while(r>=0 && row[r]==0)
        {
            r--;
        }
        int aa=0;
        if(l<=r)
        {
            aa=r-l+1;
        }
        
        l=0,r=m-1;
        while(l<m && col[l]==0)
        {
            l++;
        }
        while(r>=0 && col[r]==0)
        {
            r--;
        }
        int b=0;
        if(l<=r)
        {
            b=r-l+1;
        }
        cout<<aa<<" "<<b<<endl;
        int ans=aa*b;
        return ans;
        
        
    }
};
