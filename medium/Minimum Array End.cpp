class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        long long k=n-1;
        for(int i=0;i<64;i++)
        {
            if(!(ans & (1ll<<i)))
            {
                if(k%2)
                {
                    ans= ans | (1ll<<i);
                }
                k/=2;
            }
        }
        return ans;

    }
};
