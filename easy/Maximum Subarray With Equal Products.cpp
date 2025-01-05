class Solution {
public:
    using int128 = __int128;
    long long gcd(long long a,long long b) { if (b==0) return a; return gcd(b, a%b); }
    long long lcm(long long a,long long b) { return a/gcd(a,b)*b; }
    
    int maxLength(vector<int>& nums) {
        int max_length = 0;
        int n = nums.size();

        for (int start = 0; start < n; ++start) {
            int128 product = 1;
            long long gcd_value = 0;
            long long lcm_value = 1;

            for (int end = start; end < n; ++end) {
                if (product > numeric_limits<int128>::max() / nums[end]) break; // Prevent overflow
                product *= nums[end];
                gcd_value = gcd(gcd_value, nums[end]);
                lcm_value = lcm(lcm_value, nums[end]);

                if (product % lcm_value == 0 && product / lcm_value == gcd_value) {
                    max_length = max(max_length, end - start + 1);
                }
            }
        }
        return max_length;
    }
 
};
