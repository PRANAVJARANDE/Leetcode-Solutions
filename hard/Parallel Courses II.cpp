class Solution {
public:

    int minNumberOfSemesters(int n, vector<vector<int>>& a, int k) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        int mx=(1<<n)-1;
        vector<int>dis(mx+3,INT_MAX);
        q1.push({0,((1<<n)-1)});
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            int cst=pr.first,mask=pr.second;
            if(mask==0)return cst;

            vector<int>deg(n,0);
            for(auto x:a)
            {
                int u=x[0]-1,v=x[1]-1;
                if((mask & (1<<u)) && (mask & (1<<v)))deg[v]++;
            }

            vector<int>v1;
            for(int i=0;i<n;i++)if((mask & (1<<i)) && deg[i]==0)v1.push_back(i);
            
            int sz=v1.size();
            if(sz<k)
            {
                int nmask=mask;
                for(int i=0;i<sz;i++)
                {
                    nmask=nmask ^ (1<<v1[i]);
                    if(dis[nmask]>cst+1)
                    {
                        dis[nmask]=cst+1;
                        q1.push({dis[nmask],nmask});
                    }
                }
            }
            else
            {
                for(int j=0;j<(1<<sz);j++)
                {
                    int cnt=0;
                    for(int i=0;i<sz;i++)if(j & (1<<i))cnt++;
                    if(cnt==k)
                    {
                        int nmask=mask;
                        for(int i=0;i<sz;i++)
                        {
                            if(j & (1<<i))
                            {
                                nmask=nmask ^ (1<<v1[i]);
                                if(dis[nmask]>cst+1)
                                {
                                    dis[nmask]=cst+1;
                                    q1.push({dis[nmask],nmask});
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;   
    }
};
