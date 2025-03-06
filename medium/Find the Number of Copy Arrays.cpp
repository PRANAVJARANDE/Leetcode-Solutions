class Solution {
public:
    int countArrays(vector<int>& a, vector<vector<int>>& b) 
    {
        int n=a.size();
        int l=INT_MIN,r=INT_MAX;
        for(int i=0;i<n;i++)
        {
            b[i][0]-=a[i];
            b[i][1]-=a[i];
            l=max(l,b[i][0]);
            r=min(r,b[i][1]);
        }
        int ans=max(0,r-l+1);
        return ans;
        
        
    }
};
