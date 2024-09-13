class Solution {
public:
    
long long counter(long long k, int x, long long cho) 
{
    long long ans = 0;
    for (int i = x; i <= 60 ; i += x) 
    {
        long long p = (1LL << (i - 1));
        long long i1=(1LL << i);
        ans += ((k/i1)*p) + max(0LL, (k % i1) - p);
        if (ans > cho)
        {
            return 0;
        }
    }
    return 1;
}


    long long findMaximumNumber(long long k, int x) 
    {
        long long i=0,j=1e15;
        while(i<=j)
        {
            long long mid=i+(j-i)/2;
            if(counter(mid,x,k))
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return j;
    }
};
