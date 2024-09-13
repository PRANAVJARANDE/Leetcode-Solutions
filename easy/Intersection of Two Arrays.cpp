class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> s1;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    s1.insert(nums1[i]);
                }
            }
        }
        vector<int> v1;
        for(int x: s1)
        {
            v1.push_back(x);
        }
        return v1;
    }
};
