class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    bool check(vector<vector<int>>&a)
    {
        vector<vector<int>>tar={{1,2,3},{4,5,0}};
        return a==tar;
    }

    int slidingPuzzle(vector<vector<int>>& a) 
    {
        priority_queue<pair<int,vector<vector<int>>>,vector<pair<int,vector<vector<int>>>>,greater<pair<int,vector<vector<int>>>>>q1;
        q1.push({0,a});

        map<vector<vector<int>>,int>dis;
        dis[a]=0;

        while(!q1.empty())
        {
            int cst=q1.top().first;
            auto state=q1.top().second;
            q1.pop();

            if(check(state))return cst;
            //if(state=={{1,2,3},{4,5,0}})return cst;
            
            if(dis.find(state)==dis.end() && cst>dis[state])continue;

            for(int i=0;i<2;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(state[i][j]==0)
                    {
                        for(int z=0;z<4;z++)
                        {
                            int nx=i+dx[z];
                            int ny=j+dy[z];
                            if(nx>=0 && ny>=0 && nx<2 && ny<3)
                            {
                                swap(state[nx][ny],state[i][j]);
                                if(dis.find(state)==dis.end() || dis[state]>cst+1)
                                {
                                    dis[state]=cst+1;
                                    q1.push({dis[state],state});
                                }
                                swap(state[nx][ny],state[i][j]);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
