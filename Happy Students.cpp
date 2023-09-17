class Solution {
public:
    int countWays(vector<int>& nums) 
    {
            int n=nums.size(),ans=0;
            sort(nums.begin(),nums.end());
            for(int i=0;i<=n;i++)
            {
                   auto i1=upper_bound(nums.begin(),nums.end(),i);
                   auto i2=lower_bound(nums.begin(),nums.end(),i);
                    int c=i1-nums.begin();
                    if(i1==i2 && c==i)
                    {
                            ans++;
                    }
                    
            }
            return ans;
        
    }
};
