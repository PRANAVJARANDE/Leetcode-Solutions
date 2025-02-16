class Solution {
public:
    int n, m;
    vector<int> dx{1, -1, -1, 1};
    vector<int> dy{1, -1, 1, -1};
    vector<vector<vector<vector<int>>>> memo;

    bool issafe(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        return 1;
    }

    int helper(int i, int j, int tr, int dir, vector<vector<int>> &a) {
        if (tr == 2) return 0;
        if (memo[i][j][tr][dir] != -1) return memo[i][j][tr][dir];

        int res = 0;
        int tac = 0;
        if (a[i][j] == 0) tac = 2;

        for (int z = 0; z < 4; z++) {
            
            int nx = i + dx[z];
            int ny = j + dy[z];
            if (issafe(nx, ny) && a[nx][ny] == tac) 
            {
                if (dir == z)
                    res = max(res, helper(nx, ny, tr, z, a));
                else
                {
                    if(dir==0 && z==3)res = max(res, helper(nx, ny, tr + 1, z, a));
                    if(dir==1 && z==2)res = max(res, helper(nx, ny, tr + 1, z, a));
                    if(dir==2 && z==0)res = max(res, helper(nx, ny, tr + 1, z, a));
                    if(dir==3 && z==1)res = max(res, helper(nx, ny, tr + 1, z, a));
                }
                    
            }
        }

        return memo[i][j][tr][dir] = res + 1;
    }

    int lenOfVDiagonal(vector<vector<int>> &a) {
        n = a.size();
        m = a[0].size();
        memo.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(3, vector<int>(4, -1))));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    int res = 1;
                    for (int z = 0; z < 4; z++)
                    {
                        int nx = i + dx[z];
                        int ny = j + dy[z];
                        if (issafe(nx, ny) && a[nx][ny] == 2) 
                        {
                            res = max(res, 1 + helper(nx, ny, 0, z, a));
                        }
                    }
                    cout<<i<<" "<<j<<" "<<res<<endl;
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};
