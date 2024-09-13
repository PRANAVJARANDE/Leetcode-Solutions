class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)k++;
            nums.push_back(nums[i]);
        }
        if(k==n)return 0;
        
        vector<int>psum(2*n,0);
        for(int i=0;i<2*n;i++)
        {
            
            if(nums[i]==0)psum[i]++;
            if(i-1>=0)psum[i]+=psum[i-1];
        }
        int ans=INT_MAX;
        for(int i=n;i<2*n;i++)
        {
            ans=min(ans,psum[i]-psum[i-k]);
        }
        return ans;
    }
};
