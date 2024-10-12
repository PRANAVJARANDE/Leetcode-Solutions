class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)continue;
            int in=0;
            int j=nums[i];
            while(j%2)
            {
                j/=2;
                in++;
            }
            in--;
            int y=(nums[i] ^ (1<<in));
            ans[i]=y;
        }
        return ans;
    }
};
