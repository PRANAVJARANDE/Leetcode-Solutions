class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &a, vector<int> &b, int k) 
    {
        vector<vector<int>> ans;
        if (a.empty() || b.empty() || k <= 0) return ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({a[0] + b[0], {0, 0}});

        set<pair<int, int>> vis; 
        vis.insert({0, 0});

        while (!q.empty() && k--) 
        {
            auto in = q.top(); q.pop();
            int i1 = in.second.first;
            int i2 = in.second.second;
            ans.push_back({a[i1], b[i2]});

            if (i1 + 1 < a.size() && !vis.count({i1 + 1, i2})) {
                q.push({a[i1 + 1] + b[i2], {i1 + 1, i2}});
                vis.insert({i1 + 1, i2});
            }

            if (i2 + 1 < b.size() && !vis.count({i1, i2 + 1})) {
                q.push({a[i1] + b[i2 + 1], {i1, i2 + 1}});
                vis.insert({i1, i2 + 1});
            }
        }
        return ans;
    }
};
