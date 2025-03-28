class Solution {
public:
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,1,-1};

    bool issafe(int nx,int ny,int n,int m)
    {
        if(nx<0 || ny<0 a|| nx>=n || ny>=m)return 0;
        return 1;
    }


    vector<int> maxPoints(vector<vector<int>>& a, vector<int>& q) 
    {   
        int k=q.size();
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>v1(k,vector<int>(2,0));
        for(int i=0;i<k;i++)
        {
            v1[i][0]=q[i];
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end());
        vector<int>ans(k,0);
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        
        int cnt=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({a[0][0],{0,0}});
        for(auto x:v1)
        {
            int in=x[1];
            int val=x[0];
            
            while(!q1.empty() && q1.top().first<val)
            {
                int x=q1.top().second.first;
                int y=q1.top().second.second;
                q1.pop();
                cnt++;
                for(int z=0;z<4;z++)
                {
                    int nx=x+dx[z];
                    int ny=y+dy[z];
                    if(issafe(nx,ny,n,m) && vis[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        q1.push({a[nx][ny],{nx,ny}});
                    }
                }
            }
            ans[in]=cnt;
        }
        return ans;        
    }
};
