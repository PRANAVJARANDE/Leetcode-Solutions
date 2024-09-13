class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) 
    {
        vector<pair<int,double>> arr[n];
        int k=0;
        for(auto x:edges)
        {
            arr[x[0]].push_back({x[1],succProb[k]});
            arr[x[1]].push_back({x[0],succProb[k]});
            k++;
        }
        priority_queue<pair<int,double>> q1;
        vector<double> dist(n,0);
        dist[s]=1;
        q1.push({s,1});

        while(!q1.empty())
        {
            int in=q1.top().first;
            q1.pop();
            vector<pair<int,double>> ts=arr[in];

            for(auto x:ts)
            {
                if(dist[x.first]<dist[in]*x.second)
                {
                    dist[x.first]=dist[in]*x.second;
                    q1.push(x);
                }
            }
        }
        return dist[e];
    }
};
