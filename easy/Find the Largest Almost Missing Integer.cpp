class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1)
        {
            map<int,int>m;
            for(auto x:nums)m[x]++;
            int maxi=-1;
            for(auto x:m)
            {
                if(x.second==1)maxi=max(maxi,x.first);
            }
            return maxi;
        }
        map<int,int>vis;
        for(int i=1;i<n-1;i++)vis[nums[i]]=1;
        if(k==n || k==1)
        {
            int maxi=0;
            for(auto x:nums)maxi=max(maxi,x);
            return maxi;
        }
        if(nums[0]==nums[n-1])return -1;
        
        int ans=-1;
        if(vis[nums[0]]==0)ans=max(ans,nums[0]);
        if(vis[nums[n-1]]==0)ans=max(ans,nums[n-1]);
        return ans;
    }
};
