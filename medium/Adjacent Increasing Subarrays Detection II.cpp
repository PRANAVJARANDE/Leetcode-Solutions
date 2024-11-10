class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int n=a.size();
        vector<int> l(n,1),r(n,1);
        for(int i=1;i<n;i++)
        {
            if(a[i-1]<a[i])
            {
                l[i]=l[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                r[i]=r[i+1]+1;
            }
        }
        int ans=1;
        for(int i=0;i<n-1;i++)
        {
            int res=min(l[i],r[i+1]);
            ans=max(ans,res);
        }
        return ans;
        
        
    }
};
