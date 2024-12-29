class Solution {
public:
    int minimumOperations(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int ans=0;
        for(int j=0;j<m;j++)
        {
            int maxi=a[0][j];
            for(int i=1;i<n;i++)
            {
                ans+=max(0,maxi-a[i][j]+1);
                maxi=max(maxi+1,a[i][j]);
            }
        }
        return ans;
        
        
        
    }
};
