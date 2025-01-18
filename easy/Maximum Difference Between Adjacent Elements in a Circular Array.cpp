class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int dif=abs(nums[i]-nums[(i+1)%n]);
            ans=max(ans,dif);
        }
        return ans;
    }
};
