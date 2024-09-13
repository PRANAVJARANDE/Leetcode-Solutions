class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) 
    {
        int n=nums.size(),l=0,c=0;
        long long ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]-nums[i+1]==1)
            {
                c++;
                ans+=c;
            }
            else
            {
                c=0;
            }
        }
        ans+=n;
        return ans;
        
    }
};
