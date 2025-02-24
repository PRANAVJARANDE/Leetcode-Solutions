class Solution {
public:

    void findpar(int in,int par,vector<int>&pr,vector<vector<int>>&adj)
    {
        for(auto x:adj[in])
        {
            if(x!=par)
            {
                pr[x]=in;
                findpar(x,in,pr,adj);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& e, int bin, vector<int>&a) 
    {
        int n=e.size()+1;
        vector<vector<int>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>pr(n,-1);
        findpar(0,-1,pr,adj);



        a[bin]=0;
        queue<pair<int,int>>q1;
        q1.push({a[0],0});
        int ans=INT_MIN;

        while(!q1.empty())
        {
            int sz=q1.size();
            if(bin!=-1)bin=pr[bin];
            while(sz--)
            {
                int val=q1.front().first;
                int in=q1.front().second;
                q1.pop();
                if(adj[in].size()==1 && in!=0)ans=max(ans,val);
                
                for(auto x:adj[in])
                {
                    if(x!=pr[in])
                    {
                        int ta=a[x];
                        if(bin==x)ta/=2;
                        q1.push({val+ta,x});
                    }
                }
            }
            if(bin!=-1)a[bin]=0;
        }
        return ans;
    }
};
