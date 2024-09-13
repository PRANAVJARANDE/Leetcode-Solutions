class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        set<pair<int,int>>s1;
        for (auto x : obs)s1.insert({x[0], x[1]});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir=0;
        int i=0,j=0;
        int ans=0;
        
        for(int x:cmd) 
        {
            if(x==-2)dir=(dir+3)%4;
            else if(x==-1)dir = (dir + 1) % 4;
            else 
            {
                while(x--)
                {
                    int ni=i+directions[dir].first;
                    int nj=j+directions[dir].second;
                    if(s1.count({ni, nj}))
                    {
                        break;
                    }
                    i=ni;
                    j=nj;
                    ans=max(ans,i*i+j*j);
                }
            }
        }

        return ans;
    }
};
