class Solution {
public:

    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }


    int eraseOverlapIntervals(vector<vector<int>>& nums) 
    {
        sort(nums.begin(),nums.end(),cmp);
        int ans=0;
        int temp=nums[0][1];
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1][0]<temp)
            {
                ans++;
            }
            else
            {
                temp=nums[i+1][1];
            }
        }
        return ans;
    }
};
