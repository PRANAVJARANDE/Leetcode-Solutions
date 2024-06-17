class Solution {
public:
    long long countCompleteDayPairs(vector<int>& a) {
        long long n=a.size();
        long long ans=0;
        map<long long,long long> m;
        for(int i=0;i<n;i++)
        {
            long long h=a[i]%24;
            long long y=(24-h)%24;
            ans+=m[y];
            m[h]++;
        }
        return ans;
        
    }
};
