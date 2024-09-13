class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            int l=0,r=0,ans=1;
            while(l<n)
            {
                while(r<n && nums[r]-nums[l]<=2*k)
                {
                        r++;
                }
                ans=max(ans,r-l);
                l++;
            }
            return ans;            
    }
};
