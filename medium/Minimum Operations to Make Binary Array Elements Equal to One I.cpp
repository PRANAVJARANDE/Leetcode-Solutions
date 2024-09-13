class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(i+2<n)
                {
                    nums[i+1]=!nums[i+1];
                    nums[i+2]=!nums[i+2];
                    ans++;
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
