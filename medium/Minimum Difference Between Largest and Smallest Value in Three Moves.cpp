class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<=4)return 0;
        int l=3,r=n-1;
        int ans=INT_MAX;
        while(l>=0)
        {
            ans=min(ans,nums[r]-nums[l]);
            l--;
            r--;
        }
        return ans;
    }
};
