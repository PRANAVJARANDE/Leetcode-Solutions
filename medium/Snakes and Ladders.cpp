class Solution {
public:

    int sz;
    int snakesAndLadders(vector<vector<int>>& a) {
        int n=a.size();
        sz=n*n;
        vector<int>v1(sz + 1);
        int dir=1,in=1;
        for(int i=n-1;i>=0;i--)
        {
            if(dir==1)
            {
                for(int j=0;j<n;j++)v1[in++]=a[i][j];
                dir=0;
            }
            else
            {
                for(int j=n-1;j>=0;j--)v1[in++]=a[i][j];
                dir=1;
            }
        }
        vector<int>dis(sz+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        q1.push({0,1});
        dis[1]=0;
        while(!q1.empty())
        {
            auto fr=q1.top();
            q1.pop();

            int mv=fr.first;
            int in=fr.second;

            if(in==sz)return mv;

            for(int i=in+1;i<=min(in+6,sz);i++)
            {
                int nt=i;
                if(v1[i]!=-1)nt=v1[i];
                if(dis[nt]>dis[in]+1)
                {
                    dis[nt]=dis[in]+1;
                    q1.push({dis[in]+1,nt});
                }
            }
        }

        return -1;
    }
};
