#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        ll cnt=0;
        ll ans=0;
        for(auto x:nums)
        {
            if(x==0)cnt++;
            else cnt=0;
            ans+=cnt;
        }
        return ans;
        
    }
};
