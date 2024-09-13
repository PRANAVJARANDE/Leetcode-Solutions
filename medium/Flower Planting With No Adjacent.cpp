class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n,-1);
        vector<vector<int>> adj(n);
        for(auto x:paths)
        {
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }

        
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                queue<int> q1;
                ans[i]=1;
                q1.push(i);
                while(!q1.empty())
                {
                    int k=q1.front();
                    q1.pop();
                    for(int x: adj[k])
                    {
                        if(ans[x]==-1)
                        {
                            vector<int>ops(5,0);
                            for(int y: adj[x])
                            {
                                if(ans[y]!=-1)ops[ans[y]]=1;
                            }
                            for(int z=1;z<=4;z++)
                            {
                                if(ops[z]==0)
                                {
                                    ans[x]=z;
                                    break;
                                }
                            }
                            q1.push(x);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
