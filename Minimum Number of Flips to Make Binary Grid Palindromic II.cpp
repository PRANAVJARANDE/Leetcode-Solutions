class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        
        int n=a.size(),m=a[0].size();
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                int oc=0;
                if(a[i][j]==1)oc++;
                if(a[i][m-j-1]==1)oc++;
                if(a[n-i-1][j]==1)oc++;
                if(a[n-i-1][m-j-1]==1)oc++;
                if(oc==1 || oc==3)ans++;
                if(oc==2)ans+=2;
            }
        }
        
        int tws=0;
        int ta=0;
        if(n%2 && m%2)
        {
            if(a[n/2][m/2]==1)ans++;
        }
        
        
        if(m%2)
        {
                for(int i=0;i<n/2;i++)
                {
                    int cnt=a[i][m/2]+a[n-i-1][m/2];
                    if(cnt==2)
                    {
                        tws++;
                    }
                    if(cnt==1)
                    {
                        ta++;
                    }
                }
            
        }
        if(n%2)
        {
            
                for(int j=0;j<m/2;j++)
                {
                    int cnt=a[n/2][j]+a[n/2][m-j-1];
                    if(cnt==2)
                    {
                        tws++;
                    }
                    if(cnt==1)
                    {
                        ta++;
                    }
                }
            
        }
        tws=tws%2;
        if(tws==0)
        {
            return ans+ta;
        }
        else
        {
            if(ta==0)return ans+2;
            else return ans+ta;
        }
        
    }
};
