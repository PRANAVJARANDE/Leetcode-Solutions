class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        map<int,int>m;
        int maxi=INT_MIN;
        for(auto x:nums)
        {
            m[x]++;
            maxi=max(maxi,x);
        }
        int ans=0;
        for(auto x:m)ans+=max(0,x.first);
        if(ans==0 && m[0]==0)
        {
            return maxi;
        }
        return ans;
    }
};
