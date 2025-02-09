class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long ans=n*(n-1)/2;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            ans-=m[nums[i]-i];
            m[nums[i]-i]++;
        }
        return ans;
    }
};
