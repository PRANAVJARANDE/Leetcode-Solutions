class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        unordered_map<int,int> l,r;
        int s1=0,s2=0;
        l[0]=0;
        r[0]=0;
        for(int i=0;i<n;i++)
        {
            s1+=nums[i];
            l[s1]=i+1;
        }
        for(int i=n-1;i>=0;i--)
        {
            s2+=nums[i];
            r[s2]=n-i;
        }
        if(s1<x)
        {
            return -1;
        }
        int ans=INT_MAX;
        for(auto f:l)
        {
            int ta=x-f.first;
            int cs=f.second;
            if(r.find(ta)!=r.end())
            {
                ans=min(ans,cs+r[ta]);
            }
        }
        if(ans==INT_MAX)
            return -1;

        return ans;
    }
};
