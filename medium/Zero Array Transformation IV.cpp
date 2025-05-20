class Solution {
public:

    int qs;
    int helper(int in,int s,int index,vector<vector<int>>&q,vector<vector<int>>&dp)
    {
        if(s==0)return in;
        if(s<0 || in>=qs)return qs+1;

        if(dp[in][s]!=-1)return dp[in][s];
        //not take
        int op1=helper(in+1,s,index,q,dp);

        //take
        int op2=qs+1;
        if(q[in][0]<=index && index<=q[in][1])op2=helper(in+1,s-q[in][2],index,q,dp);
        return dp[in][s]=min(op1,op2);
    }



    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) 
    {
        qs=q.size();
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            vector<vector<int>>dp(qs+1,vector<int>(nums[i]+1,-1));
            ans=max(ans,helper(0,nums[i],i,q,dp));
        }
        if(ans==qs+1)ans=-1;
        return ans;
    }
};
