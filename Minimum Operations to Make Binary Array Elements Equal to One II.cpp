class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(p==0)
            {
                if(nums[i]==0)
                {
                    p=1;
                    ans++;
                }
            }
            else
            {
                if(nums[i]==1)
                {
                    p=0;
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
