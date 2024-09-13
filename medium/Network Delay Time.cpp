class Solution {
public:

    int helperdist(vector<vector<pair<int,int>>> g,int k)
    {
        int n=g.size();
        vector<int> dist(n,INT_MAX);
        priority_queue< pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> q1;
        dist[k]=0;
        q1.push({0,k});

        while(!q1.empty())
        {
            int w=q1.top().first;
            int nin=q1.top().second;
            q1.pop();

            vector<pair<int,int>> ts=g[nin];
            for(int i=0;i<ts.size();i++)
            {
                int nw=ts[i].second;
                int in=ts[i].first;

                if(dist[nin] < dist[in]-nw)
                {
                    dist[in]=dist[nin]+nw;
                    q1.push({dist[in],in});
                }
            }
        }

        int m=INT_MIN;
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
            m=max(m,dist[i]);
        }
        return m;

    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> g(n+1);
        for(auto x: times)
        {
            g[x[0]].push_back({x[1],x[2]});
        }

        return helperdist(g,k);
    }
};
