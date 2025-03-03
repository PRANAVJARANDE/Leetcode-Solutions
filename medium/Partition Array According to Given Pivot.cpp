class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) 
    {
        vector<int>v1,v2,v3;
        for(auto x:nums)
        {
            if(x<p)v1.push_back(x);
            else if(x==p)v2.push_back(x);
            else v3.push_back(x);
        }
        int in=0;
        for(int i=0;i<v1.size();i++)nums[in++]=v1[i];
        for(int i=0;i<v2.size();i++)nums[in++]=v2[i];
        for(int i=0;i<v3.size();i++)nums[in++]=v3[i];
        return nums;
    }
};
