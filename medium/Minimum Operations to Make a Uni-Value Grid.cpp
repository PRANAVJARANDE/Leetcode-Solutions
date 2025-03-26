class Solution {
public:
    int minOperations(vector<vector<int>>& a, int x) {
        int n = a.size();
        int m = a[0].size();
        int rem = a[0][0] % x;
        vector<int> v1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] % x != rem) return -1; 
                v1.push_back(a[i][j]);
            }
        }

        sort(v1.begin(), v1.end());
        int median = v1[v1.size() / 2]; 
        int ans = 0;

        for (int num : v1) 
        {
            ans += abs(num - median) / x;
        }

        return ans;
    }
};
