class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) 
    {
        int ans=0;
        for(int i=0;i<=k;i++)
        {
            ans+=min(a[i],a[k]);
        }
        for(int i=k+1;i<a.size();i++)
        {
            ans+=min(a[k]-1,a[i]);
        }
        return ans;
        
    }
};
