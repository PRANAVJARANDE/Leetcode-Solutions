class Solution {
public:

    int dfs(int in,vector<int>&time,vector<int>&a,int cnt,vector<int>&vis)
    {
        vis[in]=1;
        time[in]=cnt;
        //child
        if(a[in]==-1)
        {
            time[in]=-1;
            return -1;
        }
        else if(time[a[in]]!=-1)
        {
            int ans=cnt-time[a[in]]+1;
            time[in]=-1;
            return ans;
        }
        else if(vis[a[in]]==1)
        {
            time[in]=-1;
            return -1;
        }
        else
        {
            int ans=dfs(a[in],time,a,cnt+1,vis);
            time[in]=-1;
            return ans;
        }
    }


    int longestCycle(vector<int>& a) {
        int n=a.size();
        int ans=-1;
        vector<int> time(n,-1);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {   
                ans=max(ans,dfs(i,time,a,0,vis));
            }
        }
        return ans;
    }
};
