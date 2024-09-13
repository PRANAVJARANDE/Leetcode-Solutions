class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int l=0,n=nums.size(),s=0,ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            s+=nums[i];
            while(m[nums[i]]>=2)
            {
                m[nums[l]]--;
                s=s-nums[l];
                l++;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};
