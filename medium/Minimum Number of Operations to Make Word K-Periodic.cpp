class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) 
    {
        int n=s.size();
        map<string,int> m;
        for(int i=0;i<n;i+=k)
        {
            string d=s.substr(i,k);
            m[d]++;
        }
        
        int maxi=0;
        for(auto x: m)
        {
            maxi=max(maxi,x.second);
        }
        int ans=n/k;
        ans-=maxi;
        return ans;
        
    }
};
