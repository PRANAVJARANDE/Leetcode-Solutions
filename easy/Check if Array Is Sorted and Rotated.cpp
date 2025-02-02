class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int in=-1;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                in=i;
                break;
            }
        }
        if(in==-1)return 1;
        for(int i=0;i<n-1;i++)
        {
            int i1=(i+in)%n;
            int i2=(i+in+1)%n;
            if(nums[i1]>nums[i2])return 0;
        }
        return 1;
    }
};
