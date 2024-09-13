class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int,int> m;
        for(int x:nums3)
        {
            for(int y:nums4)
            {
                m[x+y]++;
            }
        }
        int ans=0;
        for(int x: nums1)
        {
            for(int y: nums2)
            {
                if(m.find(-(x+y))!=m.end())
                {
                    ans+=m[-(x+y)];
                }
            }
        }
        return ans;
    }
};
