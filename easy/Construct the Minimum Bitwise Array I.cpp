class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=nums[i];j++)
            {
                int res=j | (j+1);
                if(res==nums[i])
                {
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};
