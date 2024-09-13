class Solution {
public:

    int helper(string s1,string s2,int i,int j,int n1,int n2,vector<vector<int>>&dp)
    {
        if(i>=n1 && j>=n2)
            return 0;

        if(i>=n1)
        {
            int ans=0;
            while(j<n2)
            {
                ans++;
                j++;
            }
            return ans;
        }
        
        while(j>=n2)
        {
            int ans=0;
            while(i<n1)
            {
                ans++;
                i++;
            }
            return ans;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s1[i]==s2[j])
        {
            return dp[i][j]=helper(s1,s2,i+1,j+1,n1,n2,dp);
        }

        int op1=1+helper(s1,s2,i+1,j+1,n1,n2,dp);    //replace
        int op2=1+helper(s1,s2,i+1,j,n1,n2,dp);      //delete
        int op3=1+helper(s1,s2,i,j+1,n1,n2,dp);      //insert
        return dp[i][j]=min(op1,min(op2,op3));
    }




    int minDistance(string s1, string s2) 
    {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(s1,s2,0,0,s1.size(),s2.size(),dp);
    }
};
