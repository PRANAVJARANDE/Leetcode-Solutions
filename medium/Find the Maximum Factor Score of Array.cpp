class Solution {
public:
    
    int gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    
    long long maxScore(vector<int>& a) {
        long long ans=0;
        int n=a.size();
        for(int i=0;i<=n;i++)
        {
            long long gc=0;
            long long lc=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    gc=gcd(a[j],gc);
                    lc=lcm(a[j],lc);
                }
            }
            long long res=gc*lc;
            ans=max(ans,res);
        }
        return ans;
    }
};
