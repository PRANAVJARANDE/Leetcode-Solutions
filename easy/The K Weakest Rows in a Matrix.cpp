class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>> v1;
        for(int i=0;i<mat.size();i++)
        {
            int c=0;
            for(int j=0;j<mat[0].size() && mat[i][j]==1;j++)
            {
                c++;
            }
            v1.push_back({c,i});
        }
        sort(v1.begin(),v1.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v1[i][1]);
        }
        return ans;
    }
};
