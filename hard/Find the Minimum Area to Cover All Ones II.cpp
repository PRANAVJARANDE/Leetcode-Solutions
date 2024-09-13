class Solution {
public:
    
    int helper(int rs,int re,int cs,int ce,vector<vector<int>>&a)
    {
        int m1=INT_MAX,m2=INT_MIN,m3=INT_MAX,m4=INT_MIN;
        bool b=0;
        for(int i=rs;i<=re;i++)
        {
            for(int j=cs;j<=ce;j++)
            {
                if(a[i][j]==1)
                {
                    b=1;
                    m1=min(m1,i);
                    m2=max(m2,i);
                    m3=min(m3,j);
                    m4=max(m4,j);
                }
            }
        }
        if(b==0)return 0;
        return (m2-m1+1)*(m4-m3+1);
    }
    

    int minimumSum(vector<vector<int>>& a) 
    {
        int n=a.size(),m=a[0].size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a1=helper(0,i,0,m-1,a);
                int a2=helper(i+1,n-1,0,j,a);
                int a3=helper(i+1,n-1,j+1,m-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            int a1=helper(i,n-1,0,m-1,a);
            for(int j=0;j<m;j++)
            {
                int a2=helper(0,i-1,0,j,a);
                int a3=helper(0,i-1,j+1,m-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }

        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                int a1=helper(0,n-1,0,j,a);
                int a2=helper(0,i,j+1,m-1,a);
                int a3=helper(i+1,n-1,j+1,m-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }


        for(int j=m-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                int a1=helper(0,n-1,j,m-1,a);
                int a2=helper(0,i,0,j-1,a);
                int a3=helper(i+1,n-1,0,j-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int a1=helper(0,n-1,0,i,a);
                int a2=helper(0,n-1,i+1,j,a);
                int a3=helper(0,n-1,j+1,m-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a1=helper(0,i,0,m-1,a);
                int a2=helper(i+1,j,0,m-1,a);
                int a3=helper(j+1,n-1,0,m-1,a);
                ans=min(ans,a1+a2+a3);
            }
        }

        return ans;
        
    }
};
