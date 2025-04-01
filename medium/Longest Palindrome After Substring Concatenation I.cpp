class Solution {
public:

    int n,m;
    int helper(int i,int j,string&s,string&t,vector<vector<int>>&dp)
    {   
        if(i>=n || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;
        int x=i;
        int y=j;
        if(s[i]==t[j])
        {
            int op1=0;
            while(x<n && y>=0 && s[x]==t[y])
            {
                op1+=2;
                x++;
                y--;
            }
            int ta=0;
            for(int z=n-1;z>=x;z--)
            {
                bool p=0;
                int i1=x,i2=z;
                while(i1<=i2)
                {
                    if(s[i1]==s[i2])
                    {
                        i1++;
                        i2--;
                    }
                    else
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0)ta=max(ta,z-x+1);
            }
            for(int z=0;z<=y;z++)
            {
                bool p=0;
                int i1=z,i2=y;
                while(i1<=i2)
                {
                    if(t[i1]==t[i2])
                    {
                        i1++;
                        i2--;
                    }
                    else
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0)ta=max(ta,y-z+1);
            }
            op1+=ta;
            int op2=helper(x,j,s,t,dp);
            int op3=helper(i,y,s,t,dp);
            return dp[i][j]=max(op1,max(op2,op3));
        }
        else
        {
            int op1=helper(i,j-1,s,t,dp);
            int op2=helper(i+1,j,s,t,dp);
            return dp[i][j]=max(op1,op2);
        }
    }

    int longestPalindrome(string s, string t)
    {
        n=s.size();
        m=t.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>=i;j--)
            {
                bool p=0;
                int x=i,y=j;
                while(x<=y)
                {
                    if(s[x]==s[y])
                    {
                        x++;
                        y--;
                    }
                    else
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0)ans=max(ans,j-i+1);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=m-1;j>=i;j--)
            {
                bool p=0;
                int x=i,y=j;
                while(x<=y)
                {
                    if(t[x]==t[y])
                    {
                        x++;
                        y--;
                    }
                    else
                    {
                        p=1;
                        break;
                    }
                }
                if(p==0)ans=max(ans,j-i+1);
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        ans=max(ans,helper(0,m-1,s,t,dp));
        return ans;
    }
};
