class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        map<int,int>m;
        int mini=INT_MAX;
        for(auto x:nums)
        {
            m[x]++;
            mini=min(mini,x);
        }
        int sz=m.size();
        if(mini<k)return -1;
        if(mini==k)return sz-1;
        return sz;
    }
};
