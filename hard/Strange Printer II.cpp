class Solution {
public:
    bool isPrintable(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        map<int,int>mini_x;
        map<int,int>mini_y;
        map<int,int>maxi_x;
        map<int,int>maxi_y;
        set<int>s1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                s1.insert(a[i][j]);
                if(mini_x.find(a[i][j])==mini_x.end())mini_x[a[i][j]]=i;
                else mini_x[a[i][j]]=min(mini_x[a[i][j]],i);

                if(mini_y.find(a[i][j])==mini_y.end())mini_y[a[i][j]]=j;
                else mini_y[a[i][j]]=min(mini_y[a[i][j]],j);

                if(maxi_x.find(a[i][j])==maxi_x.end())maxi_x[a[i][j]]=i;
                else maxi_x[a[i][j]]=max(maxi_x[a[i][j]],i);

                if(maxi_y.find(a[i][j])==maxi_y.end())maxi_y[a[i][j]]=j;
                else maxi_y[a[i][j]]=max(maxi_y[a[i][j]],j);
                
            }
        }

        map<int,vector<int>>adj;
        map<int,int>deg;
        for(auto d:s1)
        {
            for(int i=mini_x[d];i<=maxi_x[d];i++)
            {
                for(int j=mini_y[d];j<=maxi_y[d];j++)
                {
                    if(a[i][j]!=d)
                    {
                        deg[a[i][j]]++;
                        adj[d].push_back(a[i][j]);
                    }
                }
            }
        }
        queue<int>q1;
        for(auto x:s1)
        {
            if(deg[x]==0)
            {
                q1.push(x);
            }
        }

        int cnt=0;
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            cnt++;
            for(auto x:adj[in])
            {
                deg[x]--;
                if(deg[x]==0)
                {
                    q1.push(x);
                }
            }
        }

        if(cnt==s1.size())return 1;
        return 0;
    }
};
