class Solution {
public:

    bool bomblies(long long x,long long y,long long r,long long a, long long b)
    {
        long long d=(x-a)*(x-a) + (y-b)*(y-b);
        if(d<=r*r)
        {
            return 1;
        }
        return 0;
    }

    int maximumDetonation(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        vector<vector<int>>v1(n);
        for(int i=0;i<n;i++)
        {
            long long x=arr[i][0],y=arr[i][1],r=arr[i][2];
            for(int j=0;j<n;j++)
            {
                long long a=arr[j][0],b=arr[j][1];
                if(i!=j && bomblies(x,y,r,a,b))
                {
                    v1[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            queue<int>q1;
            vector<bool>vis(n,0);
            q1.push(i);
            int det=0;

            while(!q1.empty())
            {
                int k=q1.front();
                q1.pop();
                if(vis[k]==1)
                {
                    continue;
                }
                vis[k]=1;
                det++;
                for(int x: v1[k])
                {
                    q1.push(x);
                }
            }
            ans=max(ans,det);
        }
        return ans;
    }
};
