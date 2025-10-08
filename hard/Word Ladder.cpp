class Solution {
public:

    int ladderLength(string s, string w, vector<string>& a) 
    {
        int sz=s.size(),n=a.size();
        int tar=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==w)
            {
                tar=i;
                break;
            }
        }
        if(tar==-1)return 0;

        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(a[i].size()!=sz)continue;
            for(int j=i+1;j<n;j++)
            {
                if(a[j].size()!=sz)continue;
                int cnt=0;
                for(int z=0;z<sz;z++)if(a[i][z]!=a[j][z])cnt++;
                if(cnt==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>dis(n,1e6);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        for(int i=0;i<n;i++)
        {
            if(a[i].size()==sz)
            {   
                int cnt=0;
                for(int j=0;j<sz;j++)if(a[i][j]!=s[j])cnt++;
                if(cnt==1)
                {
                    dis[i]=1;
                    q1.push({1,i});
                }
            }
            
        }

        while(!q1.empty())
        {
            auto cst=q1.top().first;
            auto in=q1.top().second;
            q1.pop();

            if(in==tar)return cst+1;

            for(auto x:adj[in])
            {
                if(dis[x]>dis[in]+1)
                {
                    dis[x]=dis[in]+1;
                    q1.push({dis[x],x});
                }
            }
        }
        return 0;
    }
};
