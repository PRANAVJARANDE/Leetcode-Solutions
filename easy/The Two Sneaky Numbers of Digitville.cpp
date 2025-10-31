class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        vector<int>ans;
        map<int,int>m;
        for(auto x:nums)
        {
            m[x]++;
            if(m[x]>1)ans.push_back(x);
        }
        return ans;
    }
};
