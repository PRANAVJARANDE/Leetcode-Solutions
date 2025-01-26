class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++)s+=nums[i];
        int ans=0;
        int ls=0;
        for(int i=0;i<n-1;i++)
        {
            ls+=nums[i];
            s-=nums[i];
            if(abs(ls-s)%2==0)ans++;
        }
        return ans;
    }
};
