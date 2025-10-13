class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) 
    {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                a[i][j] += a[i][j - 1];

        int ans = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                vector<int> v;
                for (int r = 0; r < n; r++)
                {
                    int cs = a[r][j];
                    if (i - 1 >= 0) cs -= a[r][i - 1];
                    v.push_back(cs);
                }
                set<int> s;
                s.insert(0);
                int prefix = 0;
                for (int x : v)
                {
                    prefix += x;
                    auto it = s.lower_bound(prefix - k);
                    if (it != s.end()) ans = max(ans, prefix - *it);
                    s.insert(prefix);
                }
            }
        }
        return ans;
    }
};
