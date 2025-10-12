class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) 
    {
        map<int,int>m;
        for(auto x:nums)m[x]++;
        int ans=0;
        for(auto x:m)
        {
            if(x.second%k==0)
            {
                ans+=(x.first*x.second);
            }
        }
        return ans;
    }
};
