#define ll long long
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) 
    {
        ll ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int tk=n/3;
        for(int i=n-2;i>=0;i-=2)
        {
            ans+=nums[i];
            tk--;
            if(tk==0)break;
        }
        return ans;
    }
};©leetcode
