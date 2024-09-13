class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int maxi=INT_MIN;
        map<int,int> m;
        for(int x: nums)
        {
            m[x]++;
            maxi=max(maxi,m[x]);
        }
        int ans=0;
        for(auto x:m)
        {
            if(x.second==maxi)
            {
                ans+=x.second;
            }
        }
        return ans;
        
    }
};
