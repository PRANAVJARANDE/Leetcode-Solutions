class Solution {
public:

    int countTriplets(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        vector<int>m(1<<16,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                m[nums[i] & nums[j]]++;
        
        for(auto x:nums)
        {
            for(int i=0;i<(1<<16);i++)
            {
                if((x & i)==0)ans+=m[i];
            }
        }
        return ans;
    }
};
