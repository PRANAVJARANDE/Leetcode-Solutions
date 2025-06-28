class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=nums[i];
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
        vector<int>v2;
        for(int i=0;i<k;i++)v2.push_back(v1[i][1]);
        sort(v2.begin(),v2.end());
        vector<int>ans;
        for(auto x:v2)ans.push_back(nums[x]);
        return ans;
    }
};
