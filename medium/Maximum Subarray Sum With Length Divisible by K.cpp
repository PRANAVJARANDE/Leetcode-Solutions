class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>psum(n+1,0);
        vector<long long>temp(k,LLONG_MAX);
        for(int i=0;i<n;i++)
        {
            psum[i+1]=nums[i]+psum[i];
        }
        long long ans=LLONG_MIN;
        for(int i=0;i<=n;i++)
        {
            if(i>=k)
            {
                ans=max(ans,psum[i]-temp[i%k]);
            }
            temp[i%k]=min(temp[i%k],psum[i]);
        }
        if(ans==LLONG_MIN)ans=0;
        return ans;
    }
};
