class Solution {
public:

    float helper(int a,int b,vector<vector<float>>&dp)
    {
        if(a<=0 && b<=0)
            return 0.5;
        
        if(a<=0)
            return 1;
        
        if(b<=0)
            return 0;

        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }

        float l1=helper(a-100,b,dp);
        float l2=helper(a-75,b-25,dp);
        float l3=helper(a-50,b-50,dp);
        float l4=helper(a-25,b-75,dp);

        return dp[a][b]=0.25*(l1+l2+l3+l4);
    }


    double soupServings(int n) 
    {
        if(n>=5000) return 1;
        vector<vector<float>> dp(n+1,vector<float>(n+1,-1));
        return helper(n,n,dp);
    }
};
