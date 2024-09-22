class Solution {
public:

    bool check(long long time,long long k, vector<int>& wt)
    {
        long long totalHeightReduced = 0;
        for (int t : wt) {
            long long low = 0, high = k;
            while (low < high) {
                long long mid = (low + high + 1) / 2;
                long long requiredTime = (long long)t * (mid * (mid + 1)) / 2;
                if (requiredTime <= time) {
                    low = mid; 
                } else {
                    high = mid - 1; 
                }
            }
            totalHeightReduced += low; 
            if (totalHeightReduced >= k) return true; 
        }
        return totalHeightReduced >= k;
    }



    long long minNumberOfSeconds(int k, vector<int>& wt) 
    {
        long long ans=1e18;
        long long l=0,r=1e18;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(check(mid,k,wt))
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
