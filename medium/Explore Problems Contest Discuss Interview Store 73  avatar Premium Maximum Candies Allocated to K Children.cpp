class Solution {
public:

    bool check(long long m,vector<int>&a,long long k)
    {
        for(auto x:a)
        {
            long long cn=x/m;
            k-=cn;
            if(k<=0)return 1;
        }
        return 0;
    }

    int maximumCandies(vector<int>& a, long long k)
    {
        long long l=1,r=0;
        for(auto x:a)r+=x;
        long long ans=0;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(check(mid,a,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        int res=ans;
        return res;
    }
};
