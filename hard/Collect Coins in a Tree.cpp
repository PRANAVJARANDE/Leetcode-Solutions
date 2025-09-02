#define ll long long
class Solution {
public:

        
    ll helper(ll in,ll par,vector<vector<ll>>&adj,vector<ll>&psum,vector<ll>&vis)
    {
        ll s=0;
        for(auto x:adj[in])
        {
            if(x!=par && vis[x]==0)
            {
                s+=helper(x,in,adj,psum,vis);
            }
        }
        psum[in]=s;
        return s+1;
    }


    ll getans(ll in,ll par,ll extra,vector<vector<ll>>&adj,vector<ll>&psum,vector<ll>&vis)
    {
        ll ans=2*psum[in]+2*extra;
        for(auto x:adj[in])
        {
            if(x!=par && vis[x]==0)
            {
                ll res=getans(x,in,extra+psum[in]-psum[x],adj,psum,vis);
                ans=min(ans,res);
            }
        }
        return ans;
    }

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) 
    {
        int n=coins.size();
        vector<vector<ll>>adj(n);
        vector<ll>deg(n,0);
        for(auto x:edges)
        {
            ll u=x[0];
            ll v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<ll>q1;
        vector<ll>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1 && coins[i]==0)
            {
                vis[i]=1;
                q1.push(i);
            }
        }
        
        while(!q1.empty())
        {
            ll in=q1.front();
            q1.pop();
            
            for(auto x:adj[in])
            {
                deg[x]--;
                if(vis[x]==0 && deg[x]==1 && coins[x]==0)
                {
                    vis[x]=1;
                    q1.push(x);
                }
            }
        }

        //iterate 2 times

        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 && deg[i]==1)
            {
                q1.push(i);
            }
        }

        ll cnt=2;
        while(cnt--)
        {
            ll sz=q1.size();
            while(sz--)
            {
                ll in=q1.front();
                q1.pop();
                vis[in]=1;

                for(auto x:adj[in])
                {
                    if(vis[x]==0)
                    {
                        deg[x]--;
                        if(deg[x]==1)
                        {
                            q1.push(x);
                        }
                    }
                }
            }
        }

        ll cr=-1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cr=i;
                break;
            }
        }
        if(cr==-1)
        {
            return 0;
        }
        //cout<<cr<<endl;

        vector<ll>psum(n,0);
        helper(cr,-1,adj,psum,vis);

        
        ll ans=getans(cr,-1,0,adj,psum,vis);

        return (int)ans;

        
    }
};
