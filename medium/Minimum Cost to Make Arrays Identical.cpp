class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        int n=a.size();
        long long ans1=0;
        for(int i=0;i<n;i++)
        {
            ans1+=abs(a[i]-b[i]);
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        long long ans2=k;
        for(int i=0;i<n;i++)
        {
            ans2+=abs(a[i]-b[i]);
        }
        long long ans=min(ans1,ans2);
        return ans;
        
    }
};
