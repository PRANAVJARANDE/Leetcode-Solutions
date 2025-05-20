class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) 
    {
        int n=nums.size();
        vector<int>psum(n+1,0);
        for(auto x:q)
        {
            psum[x[0]]++;
            psum[x[1]+1]--;
        }

        for(int i=1;i<=n;i++)
        {
            psum[i]+=psum[i-1];
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]>psum[i])return 0;
        }
        return 1;
    }
};
