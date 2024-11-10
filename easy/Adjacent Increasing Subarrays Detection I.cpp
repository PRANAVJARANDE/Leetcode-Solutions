class Solution {
public:
    
    bool help(int i,int k,vector<int>&nums)
    {
        for(int j=i+1;j<i+k;j++)
        {
            if(nums[j]<=nums[j-1])return 0;
        }
        return 1;
    }
    
    
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int sz=n-2*k;
        for(int i=0;i<=sz;i++)
        {
            bool b1=help(i,k,nums);
            bool b2=help(i+k,k,nums);
            if(b1 && b2)return 1;
        }
        return 0;
        
        
        
    }
};
