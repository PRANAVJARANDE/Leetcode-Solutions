class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        long long k=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            k+=a[i];
            k=k%p;
            a[i]=a[i]%p;
        }
        if(k==0)return 0;
        int ans=n;
        map<int,int> m;
        m[0]=-1;
        long long s=0;
        for(int i=0;i<n;i++)
        {
            s+=a[i];
            int cr=s%p;
            int req=(cr-k+p)%p;
            if(m.find(req)!=m.end())ans=min(ans,i-m[req]);
            m[cr]=i;
        }
        if(ans==n)ans=-1;
        return ans;
    }
};
