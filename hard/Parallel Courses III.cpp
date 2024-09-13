class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& arr, vector<int>& time) 
    {
        //topological sort
        vector<int>indeg(n+1,0);
        vector<vector<int>>gra(n+1);
        for(auto x: arr)
        {
            gra[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }

        vector<int> wait(n+1);
        queue<int> q1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                q1.push(i);
                wait[i]=time[i-1];
                ans=max(ans,wait[i]);
            }     
        }
        
        while(!q1.empty())
        {
            int k=q1.front();
            q1.pop();
            
            for(int x: gra[k])
            {
                indeg[x]--;
                wait[x]=max(wait[x],wait[k]+time[x-1]);
                ans=max(ans,wait[x]);
                if(indeg[x]==0)
                {
                    q1.push(x);
                }    
            }
            
        }

        return ans;
    }
};
