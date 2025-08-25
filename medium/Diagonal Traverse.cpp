class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a) 
    {
        map<int,vector<pair<int,int>>>m;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                m[i+j].push_back({j,a[i][j]});
            }
        }
        vector<int>res;
        for(auto x:m)
        {
            sort(x.second.begin(),x.second.end());
            if(x.first%2)reverse(x.second.begin(),x.second.end());
            for(auto z:x.second)res.push_back(z.second);
        }
        return res;
    }
};
