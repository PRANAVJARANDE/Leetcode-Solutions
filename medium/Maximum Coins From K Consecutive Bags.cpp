
#define all(ds) (ds).begin(), (ds).end()
#define lob(ds, x) (lower_bound(all(ds), (x)) - (ds).begin())
#define upb(ds, x) (upper_bound(all(ds), (x)) - (ds).begin())

class Solution {
public:
    
    long long min(long long a,long long b) { if (a<b) return a; return b; }
    long long max(long long a,long long b) { if (a>b) return a; return b; }
    
    
    long long maximumCoins(vector<vector<int>>& a, int k) {
        sort(a.begin(),a.end());
        long long n=a.size();
        
        vector<int>st(n);
        for(int i=0;i<n;i++)
        {
            st[i]=a[i][0];
        }
        
        vector<long long>psum(n,0),ssum(n,0);
        for(int i=0;i<n;i++)
        {
            long long l=a[i][0];
            long long r=a[i][1];
            long long v=a[i][2];
            psum[i]=(r-l+1)*v;
            if(i-1>=0)psum[i]+=psum[i-1];
        }
    
        
        for(int i=n-1;i>=0;i--)
        {
            long long l=a[i][0];
            long long r=a[i][1];
            long long v=a[i][2];
            ssum[i]=(r-l+1)*v;
            if(i+1<n)ssum[i]+=ssum[i+1];
        }
        
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long l=a[i][0],r=a[i][1],v=a[i][2];
            
            long long re=l+k-1;
            long long in=upb(st,re)-1;
            long long res=0;
            if(in-1>=0)res+=psum[in-1];
            if(i-1>=0)res-=psum[i-1];
            res+=(min(a[in][1],re)-a[in][0]+1)*a[in][2];
            
            
            long long le=r-k+1;
            long long in1=upb(st,le)-1;
            long long res1=0;
            if(in1+1<n)res1+=ssum[in1+1];
            if(i+1<n)res1-=ssum[i+1];
            if(in1>=0 && in1<n && a[in1][0]<=le && le<=a[in1][1])res1+=(a[in1][1]-le+1)*a[in1][2];
            
        
            ans=max(ans,max(res,res1));
        }
               
        return ans;
    }
};
