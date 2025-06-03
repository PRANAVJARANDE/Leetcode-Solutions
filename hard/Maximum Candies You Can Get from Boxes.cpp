class Solution {
public:
    int maxCandies(vector<int>& s, vector<int>& c, vector<vector<int>>& k, vector<vector<int>>& cb, vector<int>& ib) 
    {
        int n=s.size();
        vector<int>vis(n,0);
        set<int>have;
        queue<int>opened;
        for(auto x:ib)
        {
            have.insert(x);
            if(s[x]==1)
            {
                opened.push(x);
                vis[x]=1;
            }
        }
        

        int ans=0;
        while(!opened.empty())
        {
            int in=opened.front();
            opened.pop();   
            ans+=c[in];

            for(auto x:k[in])
            {
                if(s[x]==0)s[x]=1;
                if(vis[x]==0 && have.find(x)!=have.end())
                {
                    vis[x]=1;
                    opened.push(x);
                }
            }

            for(auto x:cb[in])
            {
                have.insert(x);
                if(vis[x]==0 && s[x]==1)
                {
                    vis[x]=1;
                    opened.push(x);
                }
            }
        }
        return ans;
    }
};
