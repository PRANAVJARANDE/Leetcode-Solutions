class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(int x: nums) m[x]++;
        int ans=0;
        for(auto x: m)
        {
            if(x.second==1)
            {
                return -1;
            }
            int k=x.second/3;
            int rem=x.second%3;
            if(rem!=0)
            {
                ans++;
            }
            ans+=k;
        }   
        return ans;
    }
};
