class Graph 
{
public:

    int n;
    vector<vector<pair<int,int>>> g;

    Graph(int x, vector<vector<int>>& e) 
    {
        n=x;
        g.resize(n);
        for(int i=0;i<e.size();i++)
        {
            g[e[i][0]].push_back(make_pair(e[i][1],e[i][2]));
        }
    }
    
    void addEdge(vector<int> e) 
    {
        g[e[0]].push_back(make_pair(e[1],e[2]));
    }

    

    
    int shortestPath(int a, int b) 
    {
    int n=g.size();
    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
    q1.push(make_pair(0,a));
    dist[a]=0;
    
    while(!q1.empty())
    {
        int w=q1.top().first;
        int nin=q1.top().second;
        q1.pop();

        if(nin==b)
        {
            return w;
        }
        
        for(int i=0;i<g[nin].size();i++)
        {
            int ptr=g[nin][i].first;
            int nwe=g[nin][i].second;
            if(nwe+w<dist[ptr])
            {
                dist[ptr]=nwe+w;
                q1.push(make_pair(dist[ptr],ptr));
            }
            
            
        }
    }

        if(dist[b]==INT_MAX)
        {
            return -1;
        }
        return dist[b];
    }
};
