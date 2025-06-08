class Solution {
public:

    vector<int>dx{-1,1,0,0,-1,1,-1,1,0};
    vector<int>dy{0,0,1,-1,-1,-1,1,1,0};
    vector<int> gridIllumination(int n, vector<vector<int>>& l, vector<vector<int>>& q) 
    {
        //precompute before queries   
        map<pair<int,int>,int>vis;
        map<int,int>r,c,d1,d2;
        for(auto x:l)
        {
            vis[{x[0],x[1]}]++;
            r[x[0]]++;
            c[x[1]]++;
            d1[x[0]+x[1]]++;
            d2[x[0]-x[1]]++;
        }

        //computation of answer
        vector<int>ans;
        for(auto x:q)
        {
            if(r[x[0]] || c[x[1]] || d1[x[0]+x[1]] || d2[x[0]-x[1]])
            {
                ans.push_back(1);
                //lamps may be lighted in surrounding
                for(int z=0;z<9;z++)
                {
                    int nx=x[0]+dx[z];
                    int ny=x[1]+dy[z];
                    while(vis[{nx,ny}]>0)
                    {
                        r[nx]--;
                        c[ny]--;
                        d1[nx+ny]--;
                        d2[nx-ny]--;
                        vis[{nx,ny}]--;
                    }
                }
            }
            else
            {
                ans.push_back(0);
                //no lamp lighted in surrounding
            }
        }
        return ans;
    }
};
