class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) 
    {
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                    if(nums[i]%mod==k)
                    {
                            nums[i]=1;
                    }
                    else
                    {
                            nums[i]=0;
                    }
            }
            long long ans=0;
            int p=0;
            unordered_map<long long,long long> m;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==1)
                {
                        p++;
                        p=p%mod;
                }
                    if(p==k)
                    {
                            ans++;
                    }
                    int rem=(p-k+mod)%mod;
                   ans+=m[rem]; 
                  m[p]++;  
            }
                return ans;
    }
};
