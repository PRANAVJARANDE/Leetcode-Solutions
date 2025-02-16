class Solution {
public:
    long long maxWeight(vector<int>& a) 
    {
        int n=a.size();
        int tk=n/4;
        sort(a.begin(),a.end(),greater<int>());
        int od=(tk+1)/2;
        int ev=tk-od;
        
        int in=0;
        long long ans=0;
        
        while(od--)
        {
            ans+=a[in];
            in++;
        }
        in++;
        while(ev--)
        {
            ans+=a[in];
            in+=2;
        }
        
        return ans;
        
    }
};
