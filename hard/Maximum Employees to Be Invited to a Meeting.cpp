class Solution {
public:

    int ans;

    int maximumInvitations(vector<int>& a) {
        int n=a.size();
        ans=0;
        vector<int>deg(n,0);
        for(int x:a)deg[x]++;
        
        queue<int>q1;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==0)
            {
                q1.push(i);
            }
        }
        vector<int>vis(n,0);
        vector<int>cnt(n,0);
        while(!q1.empty())
        {
            int in=q1.front();
            q1.pop();
            vis[in]=1;

            int nxin=a[in];
            cnt[nxin]=cnt[in]+1;
            deg[a[in]]--;
            if(deg[a[in]]==0)
            {
                q1.push(nxin);
            }
        }

        
        int ch=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int in=i;
                int l=0;
                while(vis[in]==0)
                {
                    vis[in]=1;
                    l++;
                    in=a[in];
                }
                if(l==2)
                {
                    ch+=cnt[i]+cnt[a[i]]+2;
                }
                else
                {
                    ans=max(ans,l);
                }
            }
        }

        return max(ans,ch);
    }
};
