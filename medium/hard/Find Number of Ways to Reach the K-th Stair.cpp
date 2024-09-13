class Solution {
public:

long long ncr(long long n,long long r)
{
    if(r==0)
        return 1;
        
    if(r>n-r)
        r=n-r;
        
    long long ans=1;
    for(int i=1;i<=r;i++)
        ans=ans*(n-i+1)/i;
    return ans;
}

    int waysToReachStair(int k) 
    {
        int ans=0;
        for(int i=0;i<=30;i++)
        {
            int b=i+1;
            int d=pow(2,i)-k;
            if(d<=b && d>=0)
            {
                ans+=ncr(b,d);
            }
            
        }
        return ans;
    }
};
