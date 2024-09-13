class Solution {
public:
    int n, m;
    long long INF = 1e12;

    long long maximumValueSum(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        vector<vector<long long>> v1;

        for (int i = 0; i < n; i++) {
            priority_queue<pair<int, int>> q1;
            for (int j = 0; j < m; j++) {
                q1.push({a[i][j], j});
            }
            vector<long long> temp;
            int q = 3;
            while (q--) {
                temp.push_back(q1.top().second);
                q1.pop();
            }
            v1.push_back(temp);
        }

        long long ans=-INF;
        for (int i=0;i<n;i++) 
        {
            for(int c1:v1[i])
            {
                for (int j=i+1;j<n;j++) 
                {
                    for(int c2:v1[j])
                    {
                        if(c1==c2)continue;
                        for(int k=j+1;k<n;k++)
                        {
                            for(int c3:v1[k])
                            {
                                if(c3==c2 || c3==c1)continue;
                                ans=max(ans,(long long)a[i][c1]+a[j][c2]+a[k][c3]);
                            }
                        }
                    }
                }

            }
        }

        return ans;
    }
};
