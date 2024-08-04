class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        
        vector<long long> psum(n);
        for(int i=0;i<n;i++)
        {
            psum[i]=nums[i];
            if(i-1>=0)psum[i]+=psum[i-1];
        }
        vector<long long> sum;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                long long s=psum[j];
                if(i-1>=0)s-=psum[i-1];
                sum.push_back(s);
            }
        }
        l--;
        r--;
        sort(sum.begin(),sum.end());
        int ans=0;
        int MOD=1e9 + 7;
        for(int i=l;i<=r;i++)
        {
            ans=((ans%MOD)+(sum[i]%MOD))%MOD;
        }
        return ans;

    }
};
