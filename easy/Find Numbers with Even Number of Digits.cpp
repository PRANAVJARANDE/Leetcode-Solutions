class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto x:nums)
        {
            int cnt=0;
            while(x)
            {
                x/=10;
                cnt++;
            }
            if(cnt%2==0)ans++;
        }
        return ans;
    }
};
