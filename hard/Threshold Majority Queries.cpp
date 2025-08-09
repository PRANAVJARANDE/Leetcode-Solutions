class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& q) 
    {
        int n = nums.size();
        vector<int> v1=nums;
        sort(v1.begin(),v1.end());
        v1.erase(unique(v1.begin(),v1.end()),v1.end());
        for(auto &x:nums)x=lower_bound(v1.begin(), v1.end(), x) - v1.begin();
        int m=v1.size();
        vector<vector<int>>psum(n,vector<int>(m,0));        

        for(int i=0;i<n;i++)
        {
            psum[i][nums[i]]++;
            if(i-1>=0)
            {
                for(int j=0;j<m;j++)
                {
                    psum[i][j]+=psum[i-1][j];
                }
            }
        }
        int in=0;
        vector<int>ans(q.size(),-1);
        for(auto x:q)
        {
            int l=x[0];
            int r=x[1];
            int p1=0,p2=-1;
            for(int j=0;j<m;j++)
            {
                int freq=psum[r][j];
                if(l-1>=0)freq-=psum[l-1][j];
                if(freq>p1)
                {   
                    p1=freq;
                    p2=j;
                }
            }
            if(p1>=x[2])ans[in]=v1[p2];
            in++;
        }
        return ans;
    }
};
