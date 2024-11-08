class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        int n=nums.size();
        int xs=(1<<k)-1;
        vector<int> ans(n,0);
        int ps=0;
        for(int i=0;i<n;i++)
        {
            ps=ps ^ nums[i];
            ans[n-i-1]=xs ^ ps;
        }
        return ans;
    }
};
