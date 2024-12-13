class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> s1;
        int n=nums.size();
        for(int i=0;i<n;i++)s1.insert({nums[i],i});
        long long sc=0;
        while(!s1.empty())
        {
            auto fs=*s1.begin();
            s1.erase(s1.begin());
            int in=fs.second;
            int val=fs.first;
            sc+=val;
            if(in-1>=0 && s1.find({nums[in-1],in-1})!=s1.end())
            {
                s1.erase(s1.find({nums[in-1],in-1}));
            }
            if(in+1<n && s1.find({nums[in+1],in+1})!=s1.end())
            {
                s1.erase(s1.find({nums[in+1],in+1}));
            }
        }
        return sc;
    }
};
