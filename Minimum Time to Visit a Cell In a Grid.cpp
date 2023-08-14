class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[1][0] > 1 && grid[0][1] > 1) 
        {
            return -1;  
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q1;

        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        q1.push({0,0,0});
        dist[0][0] = 0;

        while(!q1.empty())
        {
            int d = q1.top()[0];
            int i = q1.top()[1];
            int j = q1.top()[2];
            q1.pop();
            
            if(d > dist[i][j])
                continue;  
            
            if(i == m - 1 && j == n - 1)
                return d;
            
            for(int k = 0; k < 4 ; k++)
            {
                int nd = d + 1;
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= m || ny < 0 || ny >=n)
                {
                    continue;
                }

                if (grid[nx][ny] > nd) 
                {
                    int diff = grid[nx][ny] - nd;
                    if (diff & 1) 
                    {
                        ++diff;
                    }
                    nd+=diff;
                }

                if(nd < dist[nx][ny])
                {
                    dist[nx][ny] = nd;
                    q1.push({nd, nx, ny});
                }
            }
        }
        return -1;
    }
};
