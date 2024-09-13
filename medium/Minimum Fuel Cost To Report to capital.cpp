class Solution {
public:

    long long helper(int n,int s)
    {
        if(n%s==0)
            return n/s;
        return n/s +1;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n=roads.size()+1;
        vector<vector<int>>v1(n);
        vector<int>indeg(n);
        for(auto x: roads)
        {
            v1[x[0]].push_back(x[1]);
            v1[x[1]].push_back(x[0]);
        }
        queue<int>q1;
        vector<int>capa(n,1);
        indeg[0]=v1[0].size();
        for(int i=1;i<n;i++)
        {
            indeg[i]=v1[i].size();
            if(indeg[i]==1)
            {
                q1.push(i);
            }
        }
        vector<int>pass(n,1);
        long long ans=0;
        while(!q1.empty())
        {
            int k=q1.front();
            q1.pop();
            ans+=helper(pass[k],seats);
            for(int i=0;i<v1[k].size();i++)
            {
                indeg[v1[k][i]]--;
                pass[v1[k][i]]+=pass[k];
                if(v1[k][i]!=0 && indeg[v1[k][i]]==1)
                {
                    q1.push(v1[k][i]);
                }
            }
        }
        return ans;
    }
};
