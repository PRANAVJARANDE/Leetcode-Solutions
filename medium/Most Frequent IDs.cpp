class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) 
    {
        int n=nums.size();
        vector<long long> ans(n,0);
        multiset<long long> s1;
        
        map<long long,long long> m;
        
        for(int i=0;i<n;i++)
        {
            if(s1.count(m[nums[i]]))
            {
                s1.erase(s1.find(m[nums[i]]));
            }
            m[nums[i]]+=freq[i];
            s1.insert(m[nums[i]]);
            ans[i]=*s1.rbegin();
        }
        return ans;
    }
};
