class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        int ev=0,od=0;
        for(auto x:nums)
        {
            if(x%2)od++;
            else ev++;
        }
        int ans=max(ev,od);

        // E O E O E O

        int req=0;
        int cnt=0;
        for(auto x:nums)
        {
            if(x%2==req)
            {
                cnt++;
                req=1-req;   
            }
        }
        ans=max(ans,cnt);
        req=1;
        cnt=0;
        for(auto x:nums)
        {
            if(x%2==req)
            {
                cnt++;
                req=1-req;   
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};
