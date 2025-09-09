#define ll long long
class Solution {
public:
    int minJumps(vector<int>& a) 
    {
        ll n=a.size();
        map<ll,vector<ll>>m;
        for(int i=0;i<n;i++)m[a[i]].push_back(i);

        //dijkstra

        vector<ll>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
        q1.push({0,0});

        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();

            if(cst>dis[in])continue;

            //move ahead
            if(in+1<n && dis[in+1]>cst+1)
            {
                dis[in+1]=cst+1;
                q1.push({dis[in+1],in+1});
            }

            //move behind
            if(in-1>=0 && dis[in-1]>cst+1)
            {
                dis[in-1]=cst+1;
                q1.push({dis[in-1],in-1});
            }

            //move to similar one
            for(auto x:m[a[in]])
            {
                if(dis[x]>cst+1)
                {
                    dis[x]=cst+1;
                    q1.push({dis[x],x});
                }
            }
            m.erase(a[in]);
        }
        return dis[n-1];
    }
};
