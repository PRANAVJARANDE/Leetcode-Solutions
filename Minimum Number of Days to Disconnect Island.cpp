class Solution {
public:

    int n,m;
    int check(vector<vector<int>>a)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    cnt++;
                    if(cnt==2)return 2;
                    a[i][j]=0;
                    queue<pair<int,int>> q1;
                    q1.push({i,j});
                    while(!q1.empty())
                    {
                        int x=q1.front().first;
                        int y=q1.front().second;
                        q1.pop();

                        if(x+1<n && a[x+1][y]==1)
                        {
                            q1.push({x+1,y});
                            a[x+1][y]=0;
                        }
                        if(y+1<m && a[x][y+1]==1)
                        {
                            q1.push({x,y+1});
                            a[x][y+1]=0;
                        }
                        if(x-1>=0 && a[x-1][y]==1)
                        {
                            q1.push({x-1,y});
                            a[x-1][y]=0;
                        }
                        if(y-1>=0 && a[x][y-1]==1)
                        {
                            q1.push({x,y-1});
                            a[x][y-1]=0;
                        }
                    }
                }
            }
        }
        return cnt;
    }



    int minDays(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        int cnt=check(a);
        if(cnt==0 || cnt==2)return 0;
        int oc=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    oc++;
                    a[i][j]=0;
                    if(check(a)==2)return 1;
                    a[i][j]=1;
                }
            }
        }
        return min(2,oc);
    }
};
