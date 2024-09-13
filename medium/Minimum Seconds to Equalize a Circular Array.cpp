class Solution {
public:
    int minimumSeconds(vector<int>& nums) 
    {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto x: m)
        {
            vector<int>v1=x.second;
            int d=v1[0]+n-1-v1[v1.size()-1];
            for(int i=0;i<v1.size()-1;i++)
            {
                d=max(d,v1[i+1]-v1[i]-1);
            }
            ans=min(ans,(d+1)/2);
        }
        return ans;   
    }
};
