class Solution {
public:
    int MOD=1e9 +7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long>a(n,1);
        for(int z=0;z<k;z++)
        {
            for(int i=1;i<n;i++)
            {
                a[i]=((a[i]%MOD)+(a[i-1]%MOD))%MOD;
            }
        }
        return a[n-1];
    }
};
