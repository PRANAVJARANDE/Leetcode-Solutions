class Solution {
public:
    int partitionArray(vector<int>& a, int k) 
    {
        int ans=0;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=0;i<n;)
        {
            ans++;
            int mx=a[i]+k;
            while(i<n && a[i]<=mx)
            {
                i++;
            }
        }
        return ans;
    }
};
