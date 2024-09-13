class Solution {
public:
                    
    long long distributeCandies(int n, int l) 
    {
        int s=max(0,n-2*l);
        int e=min(n,l);
        long long ans=0;
        for(int i=s;i<=e;i++)
        {
            int smin=max(0,n-i-l);
            int smax=min(l,n-i);
            ans+=smax-smin+1;
        }
        return ans;
    }
};
