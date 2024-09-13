class Solution {
public:
    long long maxSum(vector<int>& nums, int ma, int k) 
    {
        long long ans=0;
            unordered_map<int,int> m;
            long long s=0;
            for(int i=0;i<k;i++)
            {
                    s+=nums[i];
                    m[nums[i]]++;
            }
            if(m.size()>=ma)
                ans=max(ans,s);
                 
            for(int i=k;i<nums.size();i++)
            {
                    m[nums[i]]++;
                    m[nums[i-k]]--;
                    if(m[nums[i-k]]==0)
                    {
                            m.erase(nums[i-k]);
                    }
                    s+=nums[i];
                    s-=nums[i-k];
                   if(m.size()>=ma)
                   {
                           ans=max(ans,s);
                   }
            }
            return ans;
    }
};
