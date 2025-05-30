class Solution {
public:
    int closestMeetingNode(vector<int>& e, int n1, int n2) 
    {
        int n=e.size();
        vector<int>vis1(n,0),vis2(n,0);
        vector<int>dis1(n,INT_MAX),dis2(n,INT_MAX);
        queue<pair<int,int>>q1;
        q1.push({n1,0});
        q1.push({n2,1});
        vis1[n1]=1;
        vis2[n2]=1;
        dis1[n1]=0;
        dis2[n2]=0;
        while(!q1.empty())
        {
            int in=q1.front().first;
            int gp=q1.front().second;
            q1.pop();
            int nx=e[in];
            if(nx!=-1)
            {
                if(gp==0)
                {
                    if(vis1[nx]==0)
                    {
                        dis1[nx]=min(dis1[nx],dis1[in]+1);
                        q1.push({nx,gp});
                        vis1[nx]=1;
                    }
                }
                else
                {
                    if(vis2[nx]==0)
                    {
                        dis2[nx]=min(dis2[nx],dis2[in]+1);
                        q1.push({nx,gp});
                        vis2[nx]=1;
                    }
                }   
            }
        }

        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,max(dis1[i],dis2[i]));
        }
        if(mini==INT_MAX)return -1;
        for(int i=0;i<n;i++)
        {
            if(max(dis1[i],dis2[i])==mini)return i;
        }
        return -1;
    }
};
