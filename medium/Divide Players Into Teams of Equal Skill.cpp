class Solution {
public:
    long long dividePlayers(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        long long s=a[0]+a[n-1];
        long long ans=0;
        for(int i=0;i<n/2;i++)
        {
            long long res=a[i]+a[n-i-1];
            if(res!=s)return -1;
            ans+=a[i]*a[n-i-1];
        }
        return ans;
    }
};
