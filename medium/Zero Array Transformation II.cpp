class Solution {
public:

    bool check(int m,vector<int>&nums,vector<vector<int>>&q)
    {
        int n=nums.size();
        vector<int>psum(n,0);
        for(int i=0;i<m;i++)
        {
            psum[q[i][0]]+=q[i][2];
            if(q[i][1]+1<n)psum[q[i][1]+1]-=q[i][2];
        }
        for(int i=1;i<n;i++)
        {
            psum[i]+=psum[i-1];
        }
        for(int i=0;i<n;i++)
        {
            if(psum[i]<nums[i])return 0;
        }
        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int ans=-1;
        int n=q.size();
        int l=0,r=n;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,nums,q))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
