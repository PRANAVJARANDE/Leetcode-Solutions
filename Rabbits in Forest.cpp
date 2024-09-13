class Solution {
public:
    int numRabbits(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(int x: nums)
            m[x]++;
        long long ans=0;
        for(auto x: m)
        {
            int i=x.second;
            int k=i/(x.first+1);
            if(i%(x.first+1)!=0)
            {
                k++;
            }
            ans+=(k*(x.first+1));
        }
        return ans;
    }
};
