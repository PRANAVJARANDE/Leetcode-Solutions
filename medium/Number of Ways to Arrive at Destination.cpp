class Solution {
public:
    int countPaths(int n, vector<vector<int>>& a) 
    {   
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:a)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q1;
        q1.push({0,0});
        vector<long long>dis(n,LLONG_MAX);
        dis[0]=0;
        int MOD=1e9 + 7;
        vector<int>res(n,0);
        res[0]=1;
        while(!q1.empty())
        {
            int d=q1.top().first;
            int in=q1.top().second;
            q1.pop();

            if(d>dis[in])continue;
            
            for(auto x:adj[in])
            {
                int ch=x.first;
                int tm=x.second;
                if(dis[in]+tm<dis[ch])
                {
                    dis[ch]=dis[in]+tm;
                    res[ch]=res[in]%MOD;
                    q1.push({dis[ch],ch});
                }
                else if(dis[in]+tm==dis[ch])
                {
                    res[ch]=((res[ch]%MOD) + (res[in]%MOD))%MOD;
                }
            }
        }
        return res[n-1];
    }
};
