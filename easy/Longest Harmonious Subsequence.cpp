class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int,int>m;
        for(auto x:nums)m[x]++;
        int ans=0;
        for(auto x:nums)
        {
            int s=m[x];
            int nx=m[x+1];
            if(nx==0)continue;
            ans=max(ans,s+nx);
        }
        return ans;
    }
};
