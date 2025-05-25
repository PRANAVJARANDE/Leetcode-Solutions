class Solution {
public:

    int n;
    int helper(int in,int pv,string &s,vector<vector<int>>&dp)
    {
        if(in>=n)return 0;
        if(dp[in][pv]!=-1)return dp[in][pv];
        int curr=s[in]-'a';



        if(pv==26)
        {
            int op1=helper(in+3,curr,s,dp);
            int op2=helper(in+1,pv,s,dp);
            return dp[in][pv]=max(op1,op2);
        }
        else
        {
            int res=0;
            int npv=pv;
            if(pv==curr)
            {
                res++;
                npv=26;
            }
            return dp[in][pv]=res+helper(in+1,npv,s,dp);
        }

        
        // //take start
        // int op1=INT_MIN;
        // if(pv==26)op1=helper(in+1,curr,s,dp);
        
        // //stop
        // int op2=INT_MIN;
        // if(pv==curr)op2=1+helper(in+1,26,s,dp);

        // //ntake
        // int op3=helper(in+1,pv,s,dp);

        // return dp[in][pv]=max(op1,max(op2,op3));
    }

    int maxSubstrings(string s) {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(27,-1));
        int ans=helper(0,26,s,dp);
        return ans;
    }
};
