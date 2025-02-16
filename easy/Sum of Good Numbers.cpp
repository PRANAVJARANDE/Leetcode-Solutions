class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            bool b=1;
            if(i-k>=0 && nums[i]<=nums[i-k])b=0;
            if(i+k<n && nums[i]<=nums[i+k])b=0;
            if(b==1)ans+=nums[i];
        }
        return ans;
    }
};
