class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& a, int m, int n) {
        int sz=a.size();
        if(m*n!=sz)return {};
        vector<vector<int>>ans(m,vector<int>(n,0));
        int in=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=a[in++];
            }
        }
        return ans;
    }
};
