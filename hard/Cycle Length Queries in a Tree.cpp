class Solution {
public:

    int calh(int x)
    {
        int ans=0;
        while(x)
        {
            x/=2;
            ans++;
        }
        return ans-1;
    }

    int findlca(int a,int b)
    {
        if(a>b)swap(a,b);
        map<int,int>vis;
        while(a)
        {
            vis[a]=1;
            a/=2;
        }
        while(b)
        {
            if(vis[b]==1)return b;
            b/=2;
        }
        return 1;
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) 
    {
        vector<int>ans;
        for(auto x:q)
        {
            int a=x[0],b=x[1];
            int lca=findlca(a,b);
            int res=calh(a)+calh(b)-2*calh(lca)+1;
            ans.push_back(res);
        }
        return ans;
    }
};
