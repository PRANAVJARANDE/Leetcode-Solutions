class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>v1;
        for(int i=0;i<32;i++)
        {
            v1.push_back(n%2);
            n/=2;
        }
        reverse(v1.begin(),v1.end());
        uint32_t ans=0;
        for(int i=0;i<32;i++)
        {
            ans+=(v1[i]*(1<<i));
        }
        return ans;
    }
};
