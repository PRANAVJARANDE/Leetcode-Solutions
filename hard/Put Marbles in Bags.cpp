class Solution {
public:
    long long putMarbles(vector<int>& a, int k) 
    {
        long long n=a.size();
        vector<long long>v1;
        for(long long i=1;i<n;i++)
        {
            v1.push_back(a[i]+a[i-1]);
        }
        sort(v1.begin(),v1.end());
        long long ans=0;
        long long i=0,j=v1.size()-1;
        long long sz=k-1;
        while(sz--)
        {
            ans+=v1[j];
            ans-=v1[i];
            j--;
            i++;
        }
        return ans;
    }
};
