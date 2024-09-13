class Solution {
public:
    int maxDistToClosest(vector<int>&nums) 
    {
        int n=nums.size();
        vector<int>v1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                v1.push_back(i);
            }
        }
        int ans=v1[0];
        for(int i=0;i<v1.size()-1;i++)
        {
            int d=(v1[i+1]-v1[i])/2;
            ans=max(ans,d);
        }
        ans=max(ans,n-1-v1[v1.size()-1]);
        return ans;
    }
};
