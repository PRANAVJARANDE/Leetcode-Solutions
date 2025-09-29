class Solution {
  public:
    int maxSubarrSum(vector<int>& temp, int a, int b) 
    {
        vector<int>v1(1,0);
        for(auto x:temp)v1.push_back(x);
        int n=v1.size();
        for(int i=1;i<n;i++)v1[i]+=v1[i-1];
        
        multiset<int>s1;
        int ans=INT_MIN;
        int l=0;
        for(int i=1;i<n;i++)
        {
            if(i-a>=0)s1.insert(v1[i-a]);
            if(!s1.empty())
            {
                int res=v1[i];
                res-=(*s1.begin());
                ans=max(ans,res);
            }
            if(i-b>=0)s1.erase(s1.find(v1[i-b]));
        }
        return ans;
    }
};
