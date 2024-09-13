class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& arr) 
    {
        vector<set<int>> gra(n);
        vector<int>deg(n,0);
        for(auto x: arr)
        {
            gra[x[0]].insert(x[1]);
            gra[x[1]].insert(x[0]);
            deg[x[0]]++;
            deg[x[1]]++;
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int a=deg[i]+deg[j];
                if(gra[i].find(j)!=gra[i].end())
                {
                    a--;
                }
                ans=max(ans,a);
            }
        }
        return ans;
    }
};
