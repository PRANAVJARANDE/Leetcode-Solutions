class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zc=0,l=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zc++;
            }
            while(zc>k && l<n)
            {
                if(nums[l]==0)
                {
                    zc--;
                }
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
