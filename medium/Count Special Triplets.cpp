class Solution {
public:

    const int MOD=1e9 + 7;
    int specialTriplets(vector<int>& a) 
    {
        long long n=a.size();
        map<long long,long long>ls,curr;
        for(int i=0;i<n;i++)ls[a[i]]++;
        long long ans=0;
        for(int i=0;i<n;i++)
        {   
            ls[a[i]]--;
            long long res=((ls[a[i]*2])%MOD * (curr[a[i]*2])%MOD)%MOD;
            ans=((ans%MOD)+(res%MOD))%MOD;
            curr[a[i]]++;
        }
        return ans;
    }
};
