#define ll long long 
class Solution {
public:
    const int MOD=1E9 + 7;
    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) 
    {
        int n = A.size();        
        int m = A[0].size();      
        int p = B[0].size(); 
        vector<vector<ll>> result(n, vector<ll>(p, 0));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                for (int j = 0; j < p; ++j) {
                    result[i][j] = ((result[i][j]%MOD) + (((A[i][k]%MOD)*(B[k][j]%MOD))%MOD))%MOD;
                }
            }
        }
        return result;
    }

     vector<vector<ll>> powerOfMatrix(vector<vector<ll>>& A, int t) 
     {
        int n=A.size();
        vector<vector<ll>> res(n, vector<ll>(n, 0));
        for(int i=0;i<n;i++)res[i][i]=1;
        while(t>0) 
        {
            if(t%2)res=multiply(res,A);
            A=multiply(A,A);
            t/=2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t,vector<int>& nums) 
    {
        vector<vector<ll>>a(26,vector<ll>(26,0));
        vector<vector<ll>>freq(1,vector<ll>(26,0));
        for(auto x:s)freq[0][x-'a']++;
        for(int i=0;i<26;i++)
            for(int j=0;j<nums[i];j++)
                a[i][(i+j+1)%26]++;
        
        a=powerOfMatrix(a,t);
        freq=multiply(freq,a);
        int ans=0;
        for(auto x:freq[0])
        {
            ans= ((ans%MOD)+(x%MOD))%MOD;
        }
        return ans;
    }
};
