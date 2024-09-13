class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>>deg(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            deg[i][1]=i;
        }
        for(auto x: roads)
        {
            deg[x[0]][0]++;
            deg[x[1]][0]++;
        }
        sort(deg.begin(),deg.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[deg[i][1]]=i+1;
        }
        long long res=0;
        for(auto x: roads)
        {
            res+=ans[x[0]]+ans[x[1]];
        }
        return res;
        
    }
};
