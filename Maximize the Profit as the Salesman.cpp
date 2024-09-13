class Solution {
public:
        
        int helper(int in,vector<vector<int>>&arr,vector<int>&dp)
        {
                if(in>=arr.size())
                        return 0;
                
                if(dp[in]!=-1)
                        return dp[in];
                
                int ntake=helper(in+1,arr,dp);
                int l=in+1,r=arr.size()-1;
                int ans=arr.size();
                while(l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(arr[in][1]<arr[mid][0])
                    {
                        r=mid-1;
                        ans=mid;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                int take=arr[in][2]+helper(ans,arr,dp);
                return dp[in]=max(take,ntake);
        }
        
    int maximizeTheProfit(int n, vector<vector<int>>& arr) 
    {
            int k=arr.size();
            sort(arr.begin(),arr.end());  
            vector<int>dp(k+1,-1);
            return helper(0,arr,dp);
    }
        
};
