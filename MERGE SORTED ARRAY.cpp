class Solution
{
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> ans;
        int i=0;
        int j=0;

        while(i<m && j<n)
        {
            if(nums1[i]>nums2[j])
            {
                ans.push_back(nums2[j]);
                j++;
            }
            else
            {
                ans.push_back(nums1[i]);
                i++;
            }
        }

        while(j<n)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }


        nums1.clear();
        for(int i=0;i<m+n;i++)
        {
            nums1.push_back(ans[i]);
        }


    }
};
