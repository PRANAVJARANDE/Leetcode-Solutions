class Solution {
public:
    
    int n;
    bool check(long long m,vector<int>&a,int k)
    {
        vector<long long>v1(n,0);
        for(int i=0;i<n;i++)
        {
            v1[i]=ceil((double)m/(double)a[i]);
        }
        long long res=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-1 && v1[i]<=0)break;
            long long tc=max(0LL,v1[i]-1);
            res+= 1+ tc*2;
            if(i+1<n)v1[i+1]-=tc;
        }
        if(res<=k)return 1;
        return 0;
    }
    
    long long maxScore(vector<int>& a, int m) 
    {
        n=a.size();
        if(m<n)return 0;
        long long l=1,r=1e15;
        long long ans=0;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(check(mid,a,m))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
