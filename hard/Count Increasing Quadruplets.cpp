#define ll long long
class Solution {
public:

    long long countQuadruplets(vector<int>&nums) 
    {
        int n=nums.size();
        ll sz=n+1;
        vector<vector<ll>>left(n,vector<ll>(sz+1,0));
        vector<vector<ll>>right(n,vector<ll>(sz+1,0));
        
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)for(int j=0;j<sz;j++)left[i][j]=left[i-1][j];
            for(int j=nums[i]+1;j<sz;j++)left[i][j]++;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(i+1<n)for(int j=0;j<sz;j++)right[i][j]=right[i+1][j];
            for(int j=0;j<nums[i];j++)right[i][j]++;
        }

        ll ans=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(nums[j]>nums[k])
                {
                    ll pv=0,nx=0;
                    if(j-1>=0)pv=left[j-1][nums[k]];
                    if(k+1<n)nx=right[k+1][nums[j]];
                    ans+=pv*nx;
                }
            }
        }
        return ans;
    }
};
