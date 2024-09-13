class Solution {
public:

    long long countGood(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        int l=0,n=nums.size(),v=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>=2)
            {
                v+=m[nums[i]]-1;
            }
            while(v>=k && l<n)
            {
                ans+=n-i;
                v-=(m[nums[l]]-1);
                m[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};
