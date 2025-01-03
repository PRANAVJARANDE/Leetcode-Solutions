class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long f2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            f2+=nums[i];
        }
        int ans=0;
        long long f1=0;
        for(int i=0;i<n-1;i++)
        {
            f1+=nums[i];
            f2-=nums[i];
            if(f1>=f2)ans++;
        }
        return ans;
    }
};
