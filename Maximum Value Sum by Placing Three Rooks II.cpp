class Solution {
public:

    long long INF=1e12;
    long long maximumValueSum(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        vector<vector<long long>> st;
        vector<vector<long long>> v1;
        for (int i = 0; i < n; i++) {
            priority_queue<pair<long long, long long>> q1;
            for (int j = 0; j < m; j++) {
                q1.push({a[i][j], j});
            }
            vector<long long> temp;
            int q = 3;
            while (q--) {
                temp.push_back(q1.top().second);
                st.push_back({q1.top().first,i,q1.top().second});
                q1.pop();
            }
            v1.push_back(temp);
        }
        sort(st.begin(),st.end());
        reverse(st.begin(),st.end());
        long long ans=-INF;
        for(long long i=0;i<n;i++)
        {
            for(long long c1:v1[i])
            {
                for(long long j=i+1;j<n;j++)
                {
                    for(long long c2:v1[j])
                    {
                        if(c1==c2)continue;
                        for(auto x:st)
                        {
                            long long c3=x[2];
                            long long row=x[1];
                            long long val=x[0];
                            if(c1==c3 || c2==c3)continue;
                            if(i==row || j==row)continue;
                            long long res=val+a[i][c1]+a[j][c2];
                            ans=max(ans,res);
                            break;
                        }
                        
                    }
                    
                }
            }
            
        }
        return ans;


    }
};
