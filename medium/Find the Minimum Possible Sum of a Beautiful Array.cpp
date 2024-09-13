class Solution {
public:
        
        long long getsum1(long long n)
        {
               return (n*(n+1))/2;
        }
        
        long long getsum2(long long n,long long a)
        {
                if(n<=0)
                {
                        return 0;
                }
                return a*n + (n*(n-1))/2;
        }
        
    long long minimumPossibleSum(int n, int t) 
    {
            long long h=t/2;
            if(n<=h)
            {
                    return getsum1(n);
            }
            return getsum1(h)+getsum2(n-h,t);
    }
};
