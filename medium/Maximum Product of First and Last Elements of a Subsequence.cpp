#define ll long long
class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) 
    {
        ll n=nums.size();
        vector<ll>ps(n+1,INT_MIN),ns(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--)
        {
            ns[i]=min(ns[i+1],(ll)nums[i]);
            ps[i]=max(ps[i+1],(ll)nums[i]);
        }
        
        // for(auto x:ps)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:ns)cout<<x<<" ";
        // cout<<endl;

        ll ans=LLONG_MIN;
        for(int i=0;i<n;i++)
        {
            int nx=i+m-1;
            if(nx<n)
            {
                if(nums[i]<0)
                {
                    if(ns[nx]!=INT_MAX)ans=max(ans,nums[i]*ns[nx]);
                }
                else
                {
                    if(ps[nx]!=INT_MIN)ans=max(ans,nums[i]*ps[nx]);
                }
            }
        }    
        return ans;



    }
};
