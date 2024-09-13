class Solution {
public:

    



    bool validateBinaryTreeNodes(int n, vector<int>& le, vector<int>& ri) 
    {

        queue<int> q1;
        vector<bool>vis(n,0);
        vector<int> v1[n];
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++)
        {
            if(le[i]!=-1)
            {
                v1[i].push_back(le[i]);
                indeg[le[i]]++;
            }
            if(ri[i]!=-1)
            {
                v1[i].push_back(ri[i]);
                indeg[ri[i]]++;
            }
        }

        //disconnected graphs
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                k++;
            }
        }
        if(k>1)
        {
            return 0;
        }

        q1.push(0);
        while(!q1.empty())
        {
            int k=q1.front();
            if(vis[k]==1)
            {
                return 0;
            }
            vis[k]=1;
            q1.pop();

            vector<int> ts=v1[k];
            if(ts.size()>2)
            {
                return 0;
            }

            for(int i=0;i<ts.size();i++)
            {
                if(vis[ts[i]]==1)
                {
                    return 0;
                }
                q1.push(ts[i]);
            }
        }
    
        return 1;
        
    }
};
