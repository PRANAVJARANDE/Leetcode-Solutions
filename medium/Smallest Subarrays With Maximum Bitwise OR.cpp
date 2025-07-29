class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>nx(n,vector<int>(32,n));
        for(int i=n-1;i>=0;i--)
        {
            int v=nums[i];
            for(int j=0;j<32;j++)
            {
                if(v & (1<<j))nx[i][j]=i;
                else if(i+1<n)nx[i][j]=nx[i+1][j];
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int res=i;
            for(int j=0;j<32;j++)
            {
                if(nx[i][j]!=n)
                {
                    res=max(res,nx[i][j]);
                }
            }
            ans[i]=res-i+1;
        }
        return ans;
    }
};
