class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int i, int j) {
        vector<vector<int>> ans;
        int rs=i,re=i;
        int cs=j,ce=j;
        ans.push_back({i,j});
        while(rs>=0 || re<n || cs>=0 || ce<m)
        {
            ce++;
            if(rs>=0)
            {
                for(int i=max(0,cs+1);i<=min(ce,m-1);i++)
                {
                    ans.push_back({rs,i});
                }
            }
            
            re++;
            if(ce<m)
            {
                for(int i=max(rs+1,0);i<=min(re,n-1);i++)
                {
                    ans.push_back({i,ce});
                }
            }

            cs--;
            if(re<n)
            {
                for(int i=min(ce-1,m-1);i>=max(0,cs);i--)
                {
                    ans.push_back({re,i});
                }
            }
            rs--;
            if(cs>=0)
            {
                for(int i=min(re-1,n-1);i>=max(0,rs);i--)
                {
                    ans.push_back({i,cs});
                }
            }
            
        }
        return ans;
    }
};
