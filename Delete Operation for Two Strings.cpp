class Solution {
public:
    int n1,n2;
    int helper(string s1,string s2,int i,int j,vector<vector<int>>&dp)
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
        if(j>=n2)
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
            return dp[i][j]=helper(s1,s2,i+1,j+1,dp);

        //delete s1
        int op1=1+helper(s1,s2,i+1,j,dp);
        //delete s2
        int op2=1+helper(s1,s2,i,j+1,dp);
        return dp[i][j]=min(op1,op2);
    }



    int minDistance(string word1, string word2) {
        n1=word1.size();
        n2=word2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(word1,word2,0,0,dp);
    }
};
