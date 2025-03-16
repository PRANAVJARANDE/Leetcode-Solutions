class Solution {
public:

    bool check(long long t,vector<int>&a,int c)
    {   
        long long cnt=0;
        for(auto x:a)
        {
            long long ta=sqrtl(t/x);
            cnt+=ta;
        }
        return cnt>=c;
    }

    long long repairCars(vector<int>& a, int c) 
    {
        long long l=0,r=1e18;
        long long ans=r;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(check(mid,a,c))
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
