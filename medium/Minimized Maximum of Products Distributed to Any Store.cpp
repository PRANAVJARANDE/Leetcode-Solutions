class Solution {
public:

    bool check(int k,vector<int>&q,int n)
    {
        int pt=0;
        for(int x:q)
        {
            int res=x/k;
            if(x%k)res++;
            pt+=res;
        }
        if(pt<=n)return 1;
        return 0;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int l=1,r=1e5 + 10;
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,q,n))
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
