class Solution {
public:

    int n,m;
    bool check(vector<vector<int>>&a)
    {
        for(auto x:a)for(auto y:x)if(y!=0)return 0;
        return 1;
    }

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};
    vector<vector<int>> flip(int i,int j,vector<vector<int>>a)
    {
        a[i][j]=1-a[i][j];
        for(int z=0;z<4;z++)
        {
            int nx=i+dx[z];
            int ny=j+dy[z];
            if(nx>=0 && ny>=0 && nx<n && ny<m)a[nx][ny]=1-a[nx][ny];
        }
        return a;
    }
    
    int minFlips(vector<vector<int>>&a) 
    {
        n=a.size();
        m=a[0].size();
        if(check(a))return 0;

        map<vector<vector<int>>,int>vis;
        queue<vector<vector<int>>>q1;
        q1.push(a);
        vis[a]=1;

        int in=0;
        while(!q1.empty())
        {
            int sz=q1.size();
            while(sz--)
            {
                auto v1=q1.front();
                q1.pop();

                if(check(v1))return in;

                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        auto flipped=flip(i,j,v1);
                        if(vis[flipped]==0)
                        {
                            vis[flipped]=1;
                            q1.push(flipped);
                        }
                    }
                }
            }
            in++;
        }   
        return -1;
    }
};
