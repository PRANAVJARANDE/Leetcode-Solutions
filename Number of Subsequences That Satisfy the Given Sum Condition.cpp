class Solution {
public:

    long long mod_pow(long long base, long long exponent, int mod) {
        if(exponent<0)
        {
            return 0;
        }
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

    int numSubseq(vector<int>& nums, int t) 
    {
        long long M=1e9+7,ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int ind=upper_bound(nums.begin(),nums.end(),t-nums[i])-nums.begin();
            
            ans=(ans%M + mod_pow(2,ind-i-1,M)%M)%M;
        }
        return ans;
    }
};
