class Solution {
public:
        
        int helper(int in,vector<int>v1,int n,int x,int k,vector<vector<int>>&dp)
        {
                if(in>=n)
                {
                        return 0;
                }
                if(dp[in][k]!=-1)
                        return dp[in][k];
                
                int op1=INT_MAX,op2=INT_MAX;
                if(in+1<n)
                {
                        int d=v1[in+1]-v1[in];
                        if(d<=x)
                        {
                                op1=d+helper(in+2,v1,n,x,k,dp);
                        }
                }
                
                if(k==1)
                {
                        op2=x+helper(in+1,v1,n,x,0,dp);
                }
                else
                {
                        op2=helper(in+1,v1,n,x,1,dp);
                }
                return dp[in][k]=min(op1,op2);
        }
        
          
    int minOperations(string s1, string s2, int x) 
    {
        vector<int> v1;
        int n=s1.size();
            for(int i=0;i<n;i++)
            {
                    if(s1[i]!=s2[i])
                    {
                        v1.push_back(i);
                    }
            }
            int y=v1.size();
            if(y%2==1)
            {
                    return -1;
            }
            if(x==0)
            {
                    return 0;
            }
            vector<vector<int>>dp(y,vector<int>(2,-1));
            return helper(0,v1,y,x,0,dp);
    }
};
