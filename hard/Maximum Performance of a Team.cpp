class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) 
    {
        vector<vector<long long>>a(n,vector<long long>(2,0));
        for(int i=0;i<n;i++)
        {
            a[i][0]=e[i];
            a[i][1]=s[i];
        }
        sort(a.begin(),a.end());
        
        vector<long long>msum(n,-1);
        priority_queue<long long,vector<long long>,greater<long long>>q1;
        long long cs=0;
        for(int i=n-1;i>=0;i--)
        {
            if(q1.size()==k)
            {
                auto val=q1.top();
                cs-=val;
                q1.pop();
                q1.push(a[i][1]);
                cs+=a[i][1];
                msum[i]=cs;
                q1.push(val);
                cs+=val;
                cs-=q1.top();
                q1.pop();
            }
            else
            {
                q1.push(a[i][1]);
                cs+=a[i][1];
                msum[i]=cs;
            }
        }

        const int MOD=1e9+7;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,a[i][0]*msum[i]);
        }
        return ans%MOD;
    }
};
