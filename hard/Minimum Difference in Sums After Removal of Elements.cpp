#define ll long long
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int sz=nums.size();
        int n=sz/3;

        vector<ll>ps(sz);
        priority_queue<ll>q1;
        ll s=0;
        for(int i=0;i<sz;i++)
        {
            s+=nums[i];
            q1.push(nums[i]);
            if(q1.size()>n)
            {
                s-=q1.top();
                q1.pop();
            }
            ps[i]=s;
        }


        vector<ll>nx(sz);
        priority_queue<ll,vector<ll>,greater<ll>>q2;
        s=0;
        for(int i=sz-1;i>=0;i--)
        {
            s+=nums[i];
            q2.push(nums[i]);
            if(q2.size()>n)
            {
                s-=q2.top();
                q2.pop();
            }
            nx[i]=s;
        }

        ll ans=LLONG_MAX;
        for(int i=n-1;i<sz-n;i++)
        {
            ll res=ps[i]-nx[i+1];
            ans=min(ans,res);
        }
        return ans;
    }
};
