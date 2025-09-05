#define ll long long
class Solution {
public:

    long long countPaths(int n, vector<vector<int>>& edges)
    {
        //adjejency list
        vector<vector<int>>adj(n+1);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        //sieve
        int mx=n+2;
        vector<bool>isprime(mx,1);
        isprime[0]=0;
        isprime[1]=0;
        for(int i=2;i<mx;i++)
        {
            if(isprime[i])
            {
                for(int j=i+i;j<mx;j+=i)
                {
                    isprime[j]=0;
                }
            }
        }

        vector<int>comp_size(n+1,0);

        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(isprime[i])
                {
                    vis[i]=1;
                }
                else
                {
                    //apply bfs and mark all non-prime visited and use dsu
                    int sz=0;
                    vector<int>temp;
                    queue<int>q1;
                    q1.push(i);
                    vis[i]=1;
                    while(!q1.empty())
                    {
                        int in=q1.front();
                        q1.pop();
                        sz++;
                        temp.push_back(in);
                        for(auto x:adj[in])
                        {
                            if(vis[x]==0 && !isprime[x])
                            {
                                vis[x]=1;
                                q1.push(x);
                            }
                        }
                    }
                    for(auto x:temp)comp_size[x]=sz;
                }
            }
        }

        //for(int i=1;i<=n;i++)cout<<comp_size[i]<<" ";

        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(isprime[i])
            {
                ll sum=0;
                vector<ll>temp;
                for(auto x:adj[i])
                {
                    if(isprime[x]==0)
                    {
                        temp.push_back(comp_size[x]);
                        sum+=comp_size[x];
                    }
                }
                ans+=sum;
                ll ra=0;
                for(auto x:temp)
                {
                    ll ta=((ll)x)*(sum-x);
                    ra+=ta;
                }
                ra/=2;
                ans+=ra;
                //cout<<i<<" "<<ans<<endl;
            }
        }
        return ans;
    }
};
