class Solution {
public:

    void build(int node, int i, int j, vector<int>& a, vector<vector<int>>& tree, int k) {
        if (i == j) {
            fill(tree[node].begin(), tree[node].end(), 0);
            int modval = a[i] % k;
            tree[node][modval] = 1;
            tree[node][k] = modval;
            return;
        }

        int mid = (i + j) / 2;
        build(2 * node + 1, i, mid, a, tree, k);
        build(2 * node + 2, mid + 1, j, a, tree, k);

        auto& l = tree[2 * node + 1];
        auto& r = tree[2 * node + 2];
        fill(tree[node].begin(), tree[node].end(), 0);

        tree[node][k] = (l[k] * r[k]) % k;
        for (int i = 0; i < k; i++) {
            tree[node][i] += l[i];
        }
        for (int i = 0; i < k; i++) {
            if (r[i]) {
                tree[node][(l[k] * i) % k] += r[i];
            }
        }
    }

    void update(int node, int i, int j, vector<vector<int>>& tree, int idx, int val, int k) {
        if (i == j) {
            fill(tree[node].begin(), tree[node].end(), 0);
            int modval = val % k;
            tree[node][modval] = 1;
            tree[node][k] = modval;
            return;
        }

        int mid = (i + j) / 2;
        if (idx <= mid)
            update(2 * node + 1, i, mid, tree, idx, val, k);
        else
            update(2 * node + 2, mid + 1, j, tree, idx, val, k);

        auto& l = tree[2 * node + 1];
        auto& r = tree[2 * node + 2];
        fill(tree[node].begin(), tree[node].end(), 0);

        tree[node][k] = (l[k] * r[k]) % k;
        for (int i = 0; i < k; i++) {
            tree[node][i] += l[i];
        }
        for (int i = 0; i < k; i++) {
            if (r[i]) {
                tree[node][(l[k] * i) % k] += r[i];
            }
        }
    }

    vector<int> query(int node, int i, int j, vector<vector<int>>& tree, int l, int r, int k) {
        if (i > r || j < l) {
            vector<int> res(k + 1, 0);
            res[k] = 1;
            return res;
        }

        if (l <= i && j <= r) return tree[node];

        int mid = (i + j) / 2;
        auto left = query(2 * node + 1, i, mid, tree, l, r, k);
        auto right = query(2 * node + 2, mid + 1, j, tree, l, r, k);

        vector<int> res(k + 1, 0);
        res[k] = (left[k] * right[k]) % k;

        for (int i = 0; i < k; i++) {
            res[i] += left[i];
        }
        for (int i = 0; i < k; i++) {
            if (right[i]) {
                res[(left[k] * i) % k] += right[i];
            }
        }

        return res;
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> tree(4 * n, vector<int>(k + 1, 0));
        build(0, 0, n - 1, nums, tree, k);

        vector<int> res;
        for (auto& q : queries) {
            int idx = q[0], val = q[1], st = q[2], x = q[3];
            update(0, 0, n - 1, tree, idx, val, k);
            auto result = query(0, 0, n - 1, tree, st, n - 1, k);
            res.push_back(result[x]);
        }
        return res;
    }
};
