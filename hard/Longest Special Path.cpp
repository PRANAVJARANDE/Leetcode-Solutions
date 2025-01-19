class Solution {
public:
    
    
    void findparent(int in,int par,vector<vector<vector<int>>>&adj,vector<vector<int>>&fpar)
    {
        for(auto x:adj[in])
        {
            if(x[0]!=par)
            {
                fpar[x[0]][0]=in,
                fpar[x[0]][1]=x[1];
                findparent(x[0],in,adj,fpar);
            }
        }
    }
    
    
    vector<int> longestSpecialPath(vector<vector<int>>& e, vector<int>& nums) 
    {
        int n=e.size()+1;
        vector<vector<vector<int>>>adj(n);
        for(auto x:e)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<vector<int>>fpar(n,vector<int>(2,-1));
        findparent(0,-1,adj,fpar);
        
        int a1=0,a2=1;
        int MAXI=1e4;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==1)
            {
                
                    vector<int>vis(5*MAXI + 2,0);
                    int in=i;
                    vis[nums[in]]++;
                    int l=i;
                    int ans=0;
                    int cnt=1;
                    while(in!=0)
                    {
                        ans+=fpar[in][1];
                        in=fpar[in][0];
                        vis[nums[in]]++;
                        cnt++;
                        while(vis[nums[in]]>1)
                        {
                            vis[nums[l]]--;
                            ans-=fpar[l][1];
                            l=fpar[l][0];
                            cnt--;
                        }
                        if(ans>a1)
                        {
                            a1=ans;
                            a2=cnt;
                        }
                        else if(ans==a1)
                        {
                            a2=min(a2,cnt);
                        }
                    }
                
            }
        }
        return {a1,a2};
    }
};
