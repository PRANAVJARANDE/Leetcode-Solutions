#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& q) 
    {
        ll ans=0;
        for(auto x:q)
        {   
            ll l=x[0],r=x[1];
            ll ops=0;
            for(int i=1;i<=15;i++)
            {
                ll st=powl(4,i-1);
                ll en=powl(4,i)-1;
                st=max(st,l);
                en=min(en,r);
                if(st<=en)
                {
                    ll cnt=en-st+1;
                    ops+=(i*cnt);
                }
            }
            ans+=(ops/2)+(ops%2);
        }
        return ans;
    }
};
