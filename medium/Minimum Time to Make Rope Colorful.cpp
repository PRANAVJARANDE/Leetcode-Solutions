class Solution {
public:
    int minCost(string s, vector<int>& nums) 
    {
        int n=s.size(),ans=0;
        for(int i=0;i<n-1;)
        {
            if(s[i]==s[i+1])
            {
                char col=s[i];
                int sum=0;
                int maxi=nums[i];
                while(s[i]==col)
                {
                    sum+=nums[i];
                    maxi=max(maxi,nums[i]);
                    i++;
                }
                ans+=sum-maxi;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
