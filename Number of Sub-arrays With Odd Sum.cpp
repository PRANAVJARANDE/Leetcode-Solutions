class Solution {
public:
    int numOfSubarrays(vector<int>& a) 
    {
        int c0=1,c1=0;
        int cnt=0;
        int MOD=1E9 +7;
        int ans=0;

        for(auto x:a)
        {
            if(x%2==1)cnt=(cnt+1)%2;
            if(cnt==0)
            {
                c0++;
                ans=((ans%MOD)+(c1%MOD))%MOD;
            }
            else
            {   
                c1++;
                ans=((ans%MOD)+(c0%MOD))%MOD;
            } 
        }
        return ans;
        
    }
};
