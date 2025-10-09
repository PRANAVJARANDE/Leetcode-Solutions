class Solution {
public:
    vector<vector<string>>fans;
    void helper(int in,vector<int>&v1,vector<string>&a,vector<vector<int>>&paths,string&s)
    {
        v1.push_back(in);
        if(paths[in].empty())
        {
            vector<string>temp;
            temp.push_back(s);
            for(int i=v1.size()-1;i>=0;i--) temp.push_back(a[v1[i]]);
            fans.push_back(temp);
        }
        else
        {
            for(auto p:paths[in])helper(p,v1,a,paths,s);
        }
        v1.pop_back();
    }


    vector<vector<string>> findLadders(string s, string w, vector<string>& a) 
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
        
        if(tar==-1)return fans;

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
        vector<vector<int>>paths(n);
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
            if(cst>dis[in])continue;
            for(auto x:adj[in])
            {
                if(dis[x]>dis[in]+1)
                {
                    paths[x].clear();
                    paths[x].push_back(in);
                    dis[x]=dis[in]+1;
                    q1.push({dis[x],x});
                }
                else if(dis[x]==dis[in]+1)
                {
                    paths[x].push_back(in);
                }
            }
        }

        if(dis[tar]==1e6)return fans;
        vector<int> v1;
        helper(tar,v1,a,paths,s);
        return fans;
    }
};
