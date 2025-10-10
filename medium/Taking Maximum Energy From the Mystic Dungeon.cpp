class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) 
    {
        int n=a.size();
        reverse(a.begin(),a.end());
        int ans=INT_MIN;
        for(int i=0;i<k;i++)
        {
            int cs=0;
            for(int j=i;j<n;j+=k)
            {
                cs+=a[j];
                ans=max(ans,cs);
            }
        }
        return ans;
    }
};
