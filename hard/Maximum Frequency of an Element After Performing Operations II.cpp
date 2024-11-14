#define all(x) (x).begin(), (x).end()
// Lower Bound Index
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())
// Upper Bound Index
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) 
    {
        int ans=1;
        int n=nums.size();
        map<int,int> m;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            ans=max(ans,m[nums[i]]);
        }
        sort(nums.begin(),nums.end());
        if(k==0)
        {
            return ans;
        }
        for(int x:nums)
        {
            for(int i=x-k;i<=x+k;i+=k)
            {
                int r=upb(nums,i+k);
                int l=lob(nums,i-k);
                int res=r-l-m[i];
                res=min(res,ops);
                ans=max(ans,res+m[i]);
            }
        }
        
        return ans;
    }
};