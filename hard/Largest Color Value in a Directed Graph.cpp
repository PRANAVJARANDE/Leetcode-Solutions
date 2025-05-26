class Solution {
public:

    int n;
    bool cycle(vector<vector<int>>& adj,vector<int>deg) 
    {
        queue<int>q1;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q1.push(i);
            }
        }

        int cnt=0; 
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            cnt++;
            for(auto x:adj[in])
            {
                deg[x]--;
                if(deg[x]==0)q1.push(x);
            }
        }

        if(cnt==n)return 0;
        return 1;
    }

    
    int helper(char ch,string s,vector<vector<int>>&adj,vector<int>deg)
    {
        queue<int>q1;
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q1.push(i);
                if(s[i]==ch)cnt[i]++;
            }
        }
        
        while(!q1.empty())
        {
            auto in=q1.front();
            q1.pop();
            for(auto x:adj[in])
            {
                if(s[x]==ch)cnt[x]=max(cnt[x],cnt[in]+1);
                else cnt[x]=max(cnt[x],cnt[in]);
                deg[x]--;
                if(deg[x]==0)q1.push(x);
            }
        }

        int maxi=0;
        for(auto x:cnt)
        {
            maxi=max(maxi,x);
        }
        return maxi;
    }

    int largestPathValue(string c, vector<vector<int>>& e) 
    {
        n=c.size();
        vector<vector<int>>adj(n);
        vector<int>deg(n,0);
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }

        if(cycle(adj,deg))return -1;

        int ans=1;
        for(char ch='a';ch<='z';ch++)
        {
            ans=max(ans,helper(ch,c,adj,deg));
        }
        return ans;
    }
};
